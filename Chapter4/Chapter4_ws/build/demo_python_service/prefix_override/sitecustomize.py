import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/honhe/learn_ros/Chapter4/Chapter4_ws/install/demo_python_service'
