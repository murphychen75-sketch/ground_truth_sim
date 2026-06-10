unique_identifier_msgs/UUID track_id  # 融合中心分配的全局唯一 ID
float64 x              # 融合后的平滑相对坐标 X（米）
float64 y              # 融合后的平滑相对坐标 Y（米）
float64 v_x            # 融合后的平滑速度 X（米/秒）
float64 v_y            # 融合后的平滑速度 Y（米/秒）
float64 size_w         # 综合估算的 3D 尺寸——宽（米）
float64 size_l         # 综合估算的 3D 尺寸——长（米）
float64 size_h         # 综合估算的 3D 尺寸——高（米）
float64[16] covariance # 4x4 协方差矩阵（按 x, y, v_x, v_y 顺序）
bool is_dark_target    # 是否为未匹配 AIS 的暗目标/可疑船只
bool is_ais_matched    # 是否已经绑定 AIS 轨迹
uint32 matched_mmsi    # 若绑定成功，对应的 AIS MMSI
string source_model_name  # 可选：Gazebo Sim 等仿真中的模型/实体名，独立真值节点可留空
