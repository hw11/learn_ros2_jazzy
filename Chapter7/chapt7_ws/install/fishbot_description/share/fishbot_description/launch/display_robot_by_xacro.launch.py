import launch
import launch_ros
from ament_index_python.packages import get_package_share_directory
import os

import launch_ros.parameter_descriptions

def generate_launch_description():
    # 获取默认的urdf路径
    urdf_package_path = get_package_share_directory('fishbot_description')
    default_xacro_path = os.path.join(urdf_package_path,'urdf','first_robot.xacro')
    # 加载rviz配置文件（如有）(需要拷贝config文件夹)
    default_rviz_config_path = os.path.join(urdf_package_path,'config','display_robot_model.rviz')
    # 声明一个urdf目录的参数，方便修改
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
        parameters=[{'robot_description':robot_description_value}], 
    )

    action_joint_state_publisher = launch_ros.actions.Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
    )

    action_riviz_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        # ros2 run rviz2 rviz2 -d xxxxxx
        arguments=['-d',default_rviz_config_path]
    )

    return launch.LaunchDescription([
        action_declare_arg_mode_path,
        action_robot_state_publisher,
        action_joint_state_publisher,
        action_riviz_node,
    ])