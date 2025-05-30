from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import rclpy
from rclpy.node import Node
from tf2_ros import TransformListener, Buffer
from tf_transformations import euler_from_quaternion, quaternion_from_euler
import math
from autopatrol_interfaces.srv import SpeechText
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import os

class PatrolNode(BasicNavigator):
    def __init__(self, node_name = 'patrol_node'):
        super().__init__(node_name)
        # 声明相关参数
        self.declare_parameter('initial_point', [0.0, 0.0, 0.0])
        # 参数不支持二维数组，使用一维数组存储多个目标点
        self.declare_parameter('target_points', [1.0, 1.0, 1.57, 2.0, 1.0, 0.0])
        self.declare_parameter('image_save_path',os.getcwd())
        
        self.initial_point = self.get_parameter('initial_point').get_parameter_value().double_array_value
        self.target_points = self.get_parameter('target_points').get_parameter_value().double_array_value
        self.image_save_path = self.get_parameter('image_save_path').get_parameter_value().string_value
        
        self.get_logger().info(f'初始点: {self.initial_point}, 目标点: {self.target_points}')
        
        self.buffer = Buffer()
        self.listener = TransformListener(self.buffer, self)

        self.speech_client = self.create_client(SpeechText, 'speak_text')

        self.cv_bridge = CvBridge()
        self.latest_image = None
        self.image_subscriber = self.create_subscription(
            Image, '/rgbd_camera/image', self.image_callback, 10)
    
    def image_callback(self, msg):
        self.latest_image = msg

    def record_img(self):
        """记录当前图像"""
        if self.latest_image is not None:
            try:
                pose = self.get_current_pose()
                cv_image = self.cv_bridge.imgmsg_to_cv2(self.latest_image)
                image_path = f"{self.image_save_path}/image_{pose.translation.x:3.2f}_{pose.translation.y:3.2f}.png"
                cv2.imwrite(image_path, cv_image)
                self.get_logger().info(f"图像已保存到: {image_path}")
            except Exception as e:
                self.get_logger().error(f"保存图像失败: {str(e)}")
        else:
            self.get_logger().warn("没有接收到最新图像")

    def get_pose_by_xyyaw(self, x, y, yaw):
        """根据x, y和yaw角度获取PoseStamped对象"""
        pose = PoseStamped()
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.header.frame_id = 'map'
        pose.pose.position.x = x
        pose.pose.position.y = y
        # 将欧拉角转换为四元数, 返回顺序为x, y, z, w
        quaternion = quaternion_from_euler(0.0, 0.0, yaw)
        pose.pose.orientation.x = quaternion[0]
        pose.pose.orientation.y = quaternion[1]
        pose.pose.orientation.z = quaternion[2]
        pose.pose.orientation.w = quaternion[3]
        return pose
    
    def init_robot_pose(self):
        """初始化机器人位置"""
        self.initial_point = self.get_parameter('initial_point').get_parameter_value().double_array_value
        initial_pose = self.get_pose_by_xyyaw(
            self.initial_point[0], self.initial_point[1], self.initial_point[2])
        self.get_logger().info(f'设置初始位置: {initial_pose}')
        self.setInitialPose(initial_pose) # 初始化导航器
        self.waitUntilNav2Active() # 启动导航器
        self.get_logger().info(f'等待导航器激活...')
   
    def get_target_points(self):
        """获取目标点列表"""
        target_points = []
        self.target_points = self.get_parameter('target_points').get_parameter_value().double_array_value
        for i in range(0, int(len(self.target_points)/ 3)):
            x = self.target_points[i*3]
            y = self.target_points[i*3 + 1]
            yaw = self.target_points[i*3 + 2]
            target_points.append([x, y, yaw])
            # target_points.append(self.get_pose_by_xyyaw(x, y, yaw))
        return target_points
    
    def nav_to_target_point(self, target_point):
        """导航到目标点"""
        self.goToPose(target_point)

        while not self.isTaskComplete():
            feedback = self.getFeedback()
            self.get_logger().info(f'剩余距离： {feedback.distance_remaining}')
            # navigator.cancelTask()
        result = self.getResult()
        self.get_logger().info(f'导航结果：{result}')

    def get_current_pose(self):
        """获取当前机器人位置"""
        while rclpy.ok():
            try:
                tf = self.buffer.lookup_transform(
                    'map', 'base_footprint', rclpy.time.Time(seconds=0), rclpy.time.Duration(seconds=1))
                transform = tf.transform
                # rotation_euler = euler_from_quaternion([
                #     transform.rotation.x,
                #     transform.rotation.y,
                #     transform.rotation.z,
                #     transform.rotation.w
                # ])
                # self.get_logger().info(
                #     f'平移:{transform.translation},旋转四元数:{transform.rotation}:旋转欧拉角:{rotation_euler}')
                return transform
            except Exception as e:
                self.get_logger().warn(f'不能够获取坐标变换，原因: {str(e)}')
    
    def speech_text(self, text):
        """调用语音合成服务"""
        while not self.speech_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('等待语音服务可用...')
        request = SpeechText.Request()
        request.text = text
        future = self.speech_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            response = future.result()
            if response.result:
                self.get_logger().info(f'语音合成成功: {text}')
            else:
                self.get_logger().warn('语音合成失败')
            self.get_logger().info(f'语音合成结果: {future.result().result}')
        else:
            self.get_logger().warn('语音合成服务响应失败')    
def main():
    rclpy.init()
    patrol = PatrolNode()
    patrol.speech_text('welcome to autopatrol robot')
    # rclpy.spin(patrol)
    patrol.init_robot_pose()
    patrol.speech_text('initial pose set')

    while rclpy.ok():
        points = patrol.get_target_points()
        patrol.speech_text('target points received')
        for point in points:
            target_pose = patrol.get_pose_by_xyyaw(point[0], point[1], point[2])
            patrol.speech_text(f'navigate to the target point: {point}')
            patrol.nav_to_target_point(target_pose)
            patrol.speech_text(f'reached the target point: {point}, ready to record image')
            patrol.record_img()
            patrol.speech_text('image recorded')
            
    rclpy.shutdown()