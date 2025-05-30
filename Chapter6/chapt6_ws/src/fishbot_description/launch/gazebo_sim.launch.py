import launch
import launch.launch_description_sources
import launch_ros
from ament_index_python.packages import get_package_share_directory
import os

import launch_ros.parameter_descriptions
from ros_gz_bridge.actions import RosGzBridge

def generate_launch_description():
    # 获取功能包的share路径
    urdf_package_path = get_package_share_directory('fishbot_description')
    default_xacro_path = os.path.join(urdf_package_path,'urdf','fishbot/fishbot.urdf.xacro')
    # 加载rviz配置文件（如有）(需要拷贝config文件夹)
    default_rviz_config_path = os.path.join(urdf_package_path,'config','display_robot_model.rviz')
    default_gazebo_world_path = os.path.join(urdf_package_path,'world','custom_room.world')
    # 声明一个xacro目录的参数，方便修改
    action_declare_arg_mode_path = launch.actions.DeclareLaunchArgument(
        name='model',default_value=str(default_xacro_path),description='记载的模型文件路径'
    )

    # 通过文件路径，获取内容，并转换为参数值对象，以供传入robot_state_publisher
    substitutions_command_result = launch.substitutions.Command(['xacro ',
        launch.substitutions.LaunchConfiguration('model')])
    robot_description_value = launch_ros.parameter_descriptions.ParameterValue(
        substitutions_command_result,value_type=str)

    action_robot_state_publisher = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        # ros2 run robot_state_publisher robot_state_publisher --ros-args -p robot_description:=xxxx
        parameters=[{'robot_description':robot_description_value},{'use_sim_time': True}], 
    )

    # action_joint_state_publisher = launch_ros.actions.Node(
    #     package='joint_state_publisher',
    #     executable='joint_state_publisher',
    #     parameters=[{'use_sim_time': True}], 
    # )

    action_rviz2_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        # ros2 run rviz2 rviz2 -d xxxxxx
        arguments=['-d',default_rviz_config_path]
    )

    action_launch_gazebo = launch.actions.IncludeLaunchDescription(
        launch.launch_description_sources.PythonLaunchDescriptionSource(
            [get_package_share_directory('ros_gz_sim'), '/launch', '/gz_sim.launch.py']
        ),
        launch_arguments=[
            ('gz_args', default_gazebo_world_path),
            ('on_exit_shutdown', 'true'),
            ('verbose', 'true')  # Enable showing logs
        ]
    )

    # Spawn the robot in Gazebo
    action_spawn_entity = launch_ros.actions.Node(
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

    # bridge ros2 and gz
    # action_ros_gz_bridge = launch_ros.actions.Node(
    #     package="ros_gz_bridge",
    #     executable="parameter_bridge",
    #     arguments=[
    #         "/cmd_vel@geometry_msgs/msg/Twist@gz.msgs.Twist", 
    #         "/odom@nav_msgs/msg/Odometry@gz.msgs.Odometry",
    #         # Joint states (Gazebo -> ROS2)
    #         "/world/default/model/fishbot/joint_state@sensor_msgs/msg/JointState@gz.msgs.Model",
    #         '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
    #         # Link poses (Gazebo -> ROS2)
    #         "/tf@tf2_msgs/msg/TFMessage[gz.msgs.Pose_V",
    #     ],
    #     output="screen",
    # )

    action_ros_gz_bridge = RosGzBridge(
            bridge_name='ros_gz_bridge',
            config_file=os.path.join(urdf_package_path,'config','ros_gz_bridge.yaml'),
        )

    # action_tf_static_node = launch_ros.actions.Node(
    #     package='tf2_ros',
    #     executable='static_transform_publisher',
    #     # ros2 run rviz2 rviz2 -d xxxxxx
    #     arguments=['0', '0', '0', '0', '0', '0', 'odom', 'base_footprint']
    # )

    return launch.LaunchDescription([
        action_declare_arg_mode_path,
        action_robot_state_publisher,
        action_launch_gazebo,
        action_spawn_entity,
        # action_tf_static_node,
        action_ros_gz_bridge,
        # action_joint_state_publisher,
        action_rviz2_node,
    ])