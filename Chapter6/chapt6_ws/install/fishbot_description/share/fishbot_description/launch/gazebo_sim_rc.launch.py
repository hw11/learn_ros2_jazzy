# Copyright 2022 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription, event_handlers
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess, RegisterEventHandler
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, Command
from launch_ros.actions import Node


def generate_launch_description():

    pkg_ros_gz_sim_demos = get_package_share_directory('fishbot_description')
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')

    # Get URDF via xacro
    xacro_file = os.path.join(pkg_ros_gz_sim_demos, 'urdf', 'fishbot', 'fishbot.rc.urdf.xacro')
    robot_desc = Command(['xacro ', xacro_file])

    rviz_launch_arg = DeclareLaunchArgument(
        'rviz', default_value='true',
        description='Open RViz.'
    )

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py'),
        ),
        launch_arguments=[
            ('gz_args', '-r ' + os.path.join(
                pkg_ros_gz_sim_demos,
                'world',
                'custom_room.world')
            )
        ], # -r is for rendering, -v 3 is for verbose
    )

    # Spawn the robot in Gazebo
    spawn_robot = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-name","fishbot",
            "-topic","/robot_description",
            "-x","0",
            "-y","0",
            "-z","0",
        ],
        output="screen",
    )

    # Bridge to forward tf and joint states to ros2
    gz_topic = '/model/fishbot'
    joint_state_gz_topic = '/world/default' + gz_topic + '/joint_state'
    # link_pose_gz_topic = gz_topic + '/pose'
    link_pose_gz_topic = '/tf'
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            # Clock (Gazebo -> ROS2)
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            # Joint states (Gazebo -> ROS2)
            joint_state_gz_topic + '@sensor_msgs/msg/JointState[gz.msgs.Model',
            # Link poses (Gazebo -> ROS2)
            link_pose_gz_topic + '@tf2_msgs/msg/TFMessage[gz.msgs.Pose_V',
            # Velocity and odometry (Gazebo -> ROS2)
            # '/cmd_vel@geometry_msgs/msg/TwistStamped@gz.msgs.Twist',
            # '/odom@nav_msgs/msg/Odometry@gz.msgs.Odometry',

            '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/scan/points@sensor_msgs/msg/PointCloud2[gz.msgs.PointCloudPacked',
            '/imu@sensor_msgs/msg/Imu[gz.msgs.IMU',
            '/rgbd_camera/image@sensor_msgs/msg/Image[gz.msgs.Image',
            '/rgbd_camera/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
            '/rgbd_camera/depth_image@sensor_msgs/msg/Image[gz.msgs.Image',
            '/rgbd_camera/points@sensor_msgs/msg/PointCloud2[gz.msgs.PointCloudPacked',
        ],
        remappings=[
            (joint_state_gz_topic, 'joint_states'),
            # ('/fishbot_diff_drive_controller/cmd_vel', '/cmd_vel'),
            # ('/fishbot_diff_drive_controller/odom', '/odom'),
            
        ],
        parameters=[{'qos_overrides./tf_static.publisher.durability': 'transient_local'}],
        output='screen'
    )

    # Get the parser plugin convert sdf to urdf using robot_description topic
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='both',
        parameters=[
            {'use_sim_time': True},
            {'robot_description': robot_desc},
        ]
    )

    # Launch rviz
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', os.path.join(pkg_ros_gz_sim_demos, 'config', 'display_robot_model.rviz')],
        condition=IfCondition(LaunchConfiguration('rviz')),
        parameters=[
            {'use_sim_time': True},
        ]
    )

    load_joint_state_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', 'fishbot_joint_state_broadcaster',
             '--set-state', 'active'],
        output='screen',
        # condition=IfCondition(LaunchConfiguration('rviz')),
    )

    load_effort_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', 'fishbot_effort_controller',
             '--set-state', 'active'],
        output='screen',
        # condition=IfCondition(LaunchConfiguration('rviz')),
    )

    load_diff_drive_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', 'fishbot_diff_drive_controller',
             '--set-state', 'active'],
        output='screen',
        # condition=IfCondition(LaunchConfiguration('rviz')),
    )

    return LaunchDescription([
        rviz_launch_arg,
        robot_state_publisher,
        gazebo,
        spawn_robot,
        RegisterEventHandler(
            event_handler=event_handlers.OnProcessExit(
                target_action=spawn_robot,
                on_exit=[load_joint_state_controller],
            )
        ), # This will load the controller after the robot is spawned (since controller needs the robot to be spawned)
        # RegisterEventHandler(
        #     event_handler=event_handlers.OnProcessExit(
        #         target_action=load_joint_state_controller,
        #         on_exit=[load_effort_controller],
        #     )
        # ),
        RegisterEventHandler(
            event_handler=event_handlers.OnProcessExit(
                target_action=load_joint_state_controller,
                on_exit=[load_diff_drive_controller],
            )
        ),
        bridge,
        rviz
    ])