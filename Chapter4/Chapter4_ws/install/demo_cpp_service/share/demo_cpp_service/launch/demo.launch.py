import launch
import launch_ros

def generate_launch_description():
    """产生launch描述"""
    # 1. 声明一个launch参数
    action_declare_arg_background_g = launch.actions.DeclareLaunchArgument('launch_arg_bg',
        default_value="150")
    # 2. 把launch参数手动传递给某个节点
    action_node_turtulesim_node = launch_ros.actions.Node(
        package='turtlesim',
        executable='turtlesim_node',
        parameters=[{'background_g':launch.substitutions.LaunchConfiguration(
            'launch_arg_bg',default="150")}],
        output='screen'
    )
    action_node_patrol_client = launch_ros.actions.Node(
        package='demo_cpp_service',
        executable='patrol_client',
        output='log'
    )
    action_node_turtule_control = launch_ros.actions.Node(
        package='demo_cpp_service',
        executable='turtle_control',
        output='both'
    )
    return launch.LaunchDescription([
        action_declare_arg_background_g,
        action_node_turtulesim_node,
        action_node_patrol_client,
        action_node_turtule_control,
    ])