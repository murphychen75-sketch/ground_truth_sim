import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/cczh/temp-code/ground_truth_sim/install/percision_sim'
