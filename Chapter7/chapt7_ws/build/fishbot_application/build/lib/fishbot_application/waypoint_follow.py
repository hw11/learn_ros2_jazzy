from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import rclpy

def main():
    rclpy.init()
    navigator = BasicNavigator()
    navigator.waitUntilNav2Active()

    goal_poses = []

    goal_pose = PoseStamped()
    goal_pose.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose.header.frame_id = 'map'
    goal_pose.pose.position.x = 2.0
    goal_pose.pose.position.y = 1.0
    # goal_pose.pose.position.z = 0.0
    goal_pose.pose.orientation.w = 1.0  # 默认朝向
    goal_poses.append(goal_pose)

    goal_pose1 = PoseStamped()
    goal_pose1.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose1.header.frame_id = 'map'
    goal_pose1.pose.position.x = 0.0
    goal_pose1.pose.position.y = 1.0
    goal_pose1.pose.orientation.w = 1.0 
    goal_poses.append(goal_pose1)

    goal_pose2 = PoseStamped()
    goal_pose2.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose2.header.frame_id = 'map'
    goal_pose2.pose.position.x = 2.0
    goal_pose2.pose.position.y = 1.0
    goal_pose2.pose.orientation.w = 1.0 
    goal_poses.append(goal_pose2)

    navigator.followWaypoints(goal_poses)

    while not navigator.isTaskComplete():
        feedback = navigator.getFeedback()
        navigator.get_logger().info(f'路点编号： {feedback.current_waypoint}')
        # navigator.cancelTask()

    result = navigator.getResult()
    navigator.get_logger().info(f'导航结果：{result}')
    
    # rclpy.spin(navigator)
    # rclpy.shutdown()