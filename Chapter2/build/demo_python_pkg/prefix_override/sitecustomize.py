import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/honhe/learn_ros/Chapter2/install/demo_python_pkg'
