import launch
import launch_ros
from ament_index_python.packages import get_package_share_directory
import os

import launch_ros.parameter_descriptions

def generate_launch_description():
    # 获取默认的urdf路径
    patrol_robot_path = get_package_share_directory('autopatrol_robot')
    default_config_path = os.path.join(patrol_robot_path,'config','patrol_config.yaml')
    
    action_patrol_node = launch_ros.actions.Node(
        package='autopatrol_robot',
        executable='patrol_node',
        name='patrol_node',
        output='screen',
        parameters=[default_config_path],
    )

    action_speaker_node = launch_ros.actions.Node(
        package='autopatrol_robot',
        executable='speaker',
        name='speaker_node',
        output='screen',
    )   
    return launch.LaunchDescription([
        action_patrol_node,
        action_speaker_node,
    ])