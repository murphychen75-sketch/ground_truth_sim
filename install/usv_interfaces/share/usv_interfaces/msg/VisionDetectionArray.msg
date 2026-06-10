# 双时间戳（语义区分）：
# - header.stamp：与该帧对应的图像采集时刻（仿真中与输入真值 stamp 对齐）
# - output_stamp：识别结果输出时刻（采集时刻 + 算法/流水线延迟；percision_sim 内可用随机延迟建模）
std_msgs/Header header
builtin_interfaces/Time output_stamp
VisionDetection[] detections        # 当前帧的检测列表
