import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/cczh/temp-code/ground_truth_sim/src/usv_fusion_new/install/usv_fusion_new'
