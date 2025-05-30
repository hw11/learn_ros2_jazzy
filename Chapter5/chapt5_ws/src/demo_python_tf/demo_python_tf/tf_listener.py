import rclpy
from rclpy.node import Node
import rclpy.time
from tf2_ros import TransformListener, Buffer #坐标变换监听器
from geometry_msgs.msg import TransformStamped #消息接口
from tf_transformations import euler_from_quaternion #四元数转欧拉角
import math

class TFListener(Node):
    def __init__(self):
        super().__init__("tf_listener")
        self.buffer_ = Buffer()
        self.listener_ = TransformListener(self.buffer_,self)
        self.timer_ = self.create_timer(1,self.get_transform)

    def get_transform(self):
        """实时查询坐标关系"""
        try:
            result = self.buffer_.lookup_transform('base_link','bottle_link',
                rclpy.time.Time(seconds=0.0),#seconds=0 最新时刻
                rclpy.time.Duration(seconds=1.0)) #timeout=1s
            transform = result.transform
            self.get_logger().info(f'平移：{transform.translation}')
            self.get_logger().info(f'旋转{transform.rotation}')
            rotation_euler = euler_from_quaternion(
                [transform.rotation.x,
                transform.rotation.y,
                transform.rotation.z,
                transform.rotation.w]
            )
            self.get_logger().info(f'旋转RPY{rotation_euler}')
        except Exception as e:
            self.get_logger().warn(f'获取坐标变换失败：原因{str(e)}')
        

def main():
    rclpy.init()
    tf_broadcaster = TFListener()
    rclpy.spin(tf_broadcaster)
    rclpy.shutdown()