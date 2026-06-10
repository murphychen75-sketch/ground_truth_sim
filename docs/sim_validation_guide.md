# 仿真与融合校验指南

本指南用于验证 `ground_truth_sim`、`percision_sim` 与 `usv_event_fusion` 组成的 **3 路视觉 + 1 路毫米波** 参考栈是否正常工作。

---

## 1. 编译与环境准备

```bash
cd /home/cczh/temp-code/ground_truth_sim

colcon build --packages-select usv_interfaces ground_truth_sim percision_sim usv_event_fusion

source install/setup.bash
```

---

## 2. 启动参考栈（推荐）

```bash
ros2 launch ground_truth_sim three_sensor_fusion_sim.launch.py
```

**期望现象**：终端中应看到 `ground_truth_node`、`range_overlay_node`、`sim_vision_{front,left,right}`、`sim_mmwave_front`、`event_fusion_node`、`rviz2` 等进程启动，无 crash。

几何规格（已写入 YAML）：

| 传感器 | 光轴 yaw | 水平 FoV |
|--------|----------|----------|
| vision front | 0° | 60° |
| vision left | -45° | 60° |
| vision right | +45° | 60° |
| mmwave front | 0° | 120° |

三路视觉相邻重叠 15°，合计 150° 对称覆盖。

关闭 RViz：`enable_rviz:=false`

---

## 3. 校验流程

另开终端并 `source install/setup.bash`。

### 3.1 节点存活

```bash
ros2 node list
```

应包含：

- `/ground_truth_node`
- `/static_tf_broadcaster`（或 `static_frame_publisher`）
- `/range_overlay_node`
- `/sim_vision_front`, `/sim_vision_left`, `/sim_vision_right`
- `/sim_mmwave_front`
- `/event_fusion_node`

### 3.2 真值与视场 Overlay

```bash
ros2 topic hz /sim/ground_truth          # 约 50 Hz
ros2 topic hz /sim/range_overlay_markers   # 约 1 Hz
```

RViz 中 **FoV Overlays** 层应显示 3 个蓝色视觉扇形 + 1 个绿色毫米波扇形 + 真值环带（订阅 `/sim/range_overlay_markers`）。

### 3.3 传感器输出

```bash
ros2 topic hz /vision/front/detections   # 约 25 Hz
ros2 topic hz /vision/left/detections
ros2 topic hz /vision/right/detections
ros2 topic hz /mmwave/front/targets      # 约 15 Hz
```

```bash
ros2 topic echo /vision/front/detections --once
```

验证点：`detections` 含噪声后的 `azimuth`/`distance_predict`；`header.frame_id` 为 `camera_front_link`。

### 3.4 TF

```bash
ros2 run tf2_ros tf2_echo base_link camera_front_link
ros2 run tf2_ros tf2_echo base_link mmwave_front_link
```

应持续输出平移与旋转，无 `lookupTransform` 异常。

### 3.5 融合输出

```bash
ros2 topic echo /fusion/snapshot --once
ros2 topic hz /fusion/track_markers
```

- `/fusion/snapshot` 中应有 **confirmed** 航迹（启动数秒后）
- `/fusion/track_markers` 中 `fusion_history` 折线需同一航迹至少两次更新后才可见

---

## 4. 分层启动（调试）

```bash
# 终端 1：真值 + FoV overlay（无 RViz）
ros2 launch ground_truth_sim ground_truth_sim.launch.py use_rviz:=false \
  range_overlay_params_file:=$(ros2 pkg prefix ground_truth_sim)/share/ground_truth_sim/config/three_sensor_overlay_params.yaml

# 终端 2：3V+1R 传感器
ros2 launch percision_sim three_sensor_sim.launch.py

# 终端 3：融合
ros2 launch usv_event_fusion event_fusion.launch.py \
  io_params_file:=$(ros2 pkg prefix usv_event_fusion)/share/usv_event_fusion/config/event_fusion_three_sensor_io.yaml

# 终端 4：RViz
rviz2 -d $(ros2 pkg prefix ground_truth_sim)/share/ground_truth_sim/rviz/three_sensor_fusion_view.rviz
```

---

## 5. 故障排查

| 现象 | 可能原因 |
|------|----------|
| RViz 无 FoV 扇形 | 未订阅 `/sim/range_overlay_markers`；或 `range_overlay_node` 未启动 |
| 视觉 Marker 为空但真值正常 | 目标不在该相机 60° 扇区内（设计行为） |
| 融合无输出 | `event_fusion_io` 话题与传感器不一致；检查 `vision_topics` / `mmwave_topic` |
| TF 报错 | `ground_truth_sim.launch.py` 未启动，`static_tf_broadcaster` 缺失 |

---

## 6. 旧版栈说明

- `full_stack_sim.launch.py`：单路 `sensors_sim`，与 `ground_truth_view.rviz` 多路话题不完全匹配，仅作 legacy 参考。
- `multi_sensor_sim.launch.py`：4 视觉 + 4 毫米波布局，与 3V+1R 参考栈无关。
- `usv_fusion` 包已弃用；融合请使用 `usv_event_fusion`。
