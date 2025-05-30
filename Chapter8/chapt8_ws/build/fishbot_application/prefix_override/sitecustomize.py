import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/honhe/learn_ros/Chapter8/chapt8_ws/install/fishbot_application'
