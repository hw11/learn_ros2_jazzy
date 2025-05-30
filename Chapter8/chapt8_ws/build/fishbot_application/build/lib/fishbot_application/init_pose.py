from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import rclpy

def main():
    rclpy.init()
    navigator = BasicNavigator()

    # 设置初始位置和朝向
    initial_pose = PoseStamped()
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    initial_pose.header.frame_id = 'map'
    initial_pose.pose.position.x = 0.0
    initial_pose.pose.position.y = 0.0
    # initial_pose.pose.position.z = 0.0
    initial_pose.pose.orientation.w = 1.0  # 默认朝向

    # 初始化导航器
    navigator.setInitialPose(initial_pose)

    # 启动导航器
    navigator.waitUntilNav2Active()

    print("Initial pose set and navigator is active.")
    
    rclpy.spin(navigator)
    rclpy.shutdown()