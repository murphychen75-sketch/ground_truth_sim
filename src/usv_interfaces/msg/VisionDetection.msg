string camera_id           # 摄像头标识（如 "front"/"left"/"right"），单个摄像头覆盖 90° 视场
string class_name          # 目标类别名称
int32 class_id             # 目标类别 ID（与 class_name 对应的数值标签）
float64 azimuth            # 目标相对该摄像头光心的水平方位角（弧度）
float64 distance_predict   # 单目预测的相对直线距离（米）
float64 size_w             # 预测的可见横向宽度（米，沿相机水平视场方向）
float64 size_h             # 预测的可见高度（米）
float64 pixel_width        # 检测框水平像素宽度（px），融合匹配用
float64 confidence         # 检测置信度（0~1），融合节点按距离动态调节协方差
