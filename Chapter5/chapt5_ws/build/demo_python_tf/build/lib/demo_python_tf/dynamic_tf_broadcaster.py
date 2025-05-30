import rclpy
from rclpy.node import Node
from tf2_ros import TransformBroadcaster #坐标发布器
from geometry_msgs.msg import TransformStamped #消息接口
from tf_transformations import quaternion_from_euler #欧拉角转四元数
import math

class TFBroadcaster(Node):
    def __init__(self):
        super().__init__("tf_broadcaster")
        self.broadcaster_ = TransformBroadcaster(self)
        self.timer_ = self.create_timer(0.01,self.publish_tf)

    def publish_tf(self):
        """发布tf 从camera_link到bottle_link之间的坐标系"""
        transform = TransformStamped()
        transform.header.stamp = self.get_clock().now().to_msg()
        transform.header.frame_id = "camera_link" # 父坐标系的id
        transform.child_frame_id = "bottle_link"
        transform.transform.translation.x = 0.2
        transform.transform.translation.y = 0.3
        transform.transform.translation.z = 0.5
        # 欧拉角转四元数
        rotation_quat = quaternion_from_euler(0, 0, 0)
        transform.transform.rotation.x = rotation_quat[0]
        transform.transform.rotation.y = rotation_quat[1]
        transform.transform.rotation.z = rotation_quat[2]
        transform.transform.rotation.w = rotation_quat[3]
      	# 发布坐标变换
        self.broadcaster_.sendTransform(transform)
        self.get_logger().info(f"发布动态TF:{transform}")

def main():
    rclpy.init()
    tf_broadcaster = TFBroadcaster()
    rclpy.spin(tf_broadcaster)
    rclpy.shutdown()