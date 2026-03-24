# USV 传感器仿真套件

该工作区聚合了三个彼此解耦、可单独部署的 ROS 2 Python/C++ 功能包，用于在无人船（USV）多传感器融合方案中快速搭建真值生成器与多源传感器模拟：

- `ground_truth_sim`：负责生成高频真值与 RViz 轨迹图层，支持 CTRV 运动模型和可配置目标数量。
- `percision_sim`：基于真值话题派生视觉、AIS、导航雷达与 4D 毫米波等仿真节点。
- `usv_interfaces`：对外公开统一的消息/服务/动作接口及话题常量，保证多语言节点间的数据契约。

> 推荐将三个包放置在同一个 ROS 2 工作区内构建，便于 `ros2 launch ground_truth_sim ground_truth_sim.launch.py` 一键启动真值与所需的感知模拟节点。

## 仓库结构

| 目录 | 说明 |
| --- | --- |
| `src/` | ROS 2 工作区的源代码目录，包含所有自研包。|
| `src/sim/` | `ground_truth_sim` 源代码（节点、TF、launch、RViz、参数）。|
| `src/percision_sim/` | 视觉 / AIS / 导航雷达 / 毫米波仿真节点与统一参数 YAML。|
| `src/usv_interfaces/` | 自定义消息（msg）、服务（srv）、动作（action）及话题常量。|
| `install/`、`build/`、`log/` | colcon 构建生成的安装/产物/日志目录，可随构建刷新。|

## 功能包概览

### 深入阅读

- [ground_truth_sim 详细说明](./src/sim/README.md)
- [percision_sim 详细说明](./src/percision_sim/README.md)
- [usv_interfaces 接口列表](./src/usv_interfaces/README.md)

### ground_truth_sim
- CTRV（Constant Turn Rate and Velocity）模型以 50 Hz 推进全局目标状态，支持随机转向、衰减与自定义数量/尺寸。
- 发布 `/sim/ground_truth`（`usv_interfaces/msg/GlobalTrackArray`）和 `/sim/ground_truth_markers`（`visualization_msgs/msg/MarkerArray`）。
- 自带 `rviz/ground_truth_view.rviz`，`ground_truth_sim.launch.py` 可选启动 RViz 及各仿真节点。
- 主要参数集中在 `src/sim/config/ground_truth_params.yaml`，通过 `params_file` launch 参数覆盖。

### percision_sim
- 面向多传感器融合的四个 ROS 2 节点：`sim_vision_node`、`sim_ais_node`、`sim_nav_radar_node`、`sim_mmwave_node`。
- 统一参数文件 `src/percision_sim/config/percision_sim_params.yaml`，可加载到任意节点（`--ros-args --params-file ...`）。
- 每个节点都提供 RViz Marker（球体/文本/贴地块/圆柱+箭头）便于调试。
- 提供 `launch/multi_sensor_sim.launch.py` + `config/multi_sensor_params.yaml`，可一键启动四摄像头（25 Hz, 90° FoV）与四毫米波雷达（15 Hz, 120° FoV），并配套 `rviz/ground_truth_view.rviz` 默认打开 `/sim/ground_truth_markers`、`/vision/markers`、`/ais/markers`、`/nav_radar/markers`、`/mmwave/markers`，免去每次手动勾选。`ground_truth_node` 的 `annulus_radius_min/max` 也在同一个 YAML 中暴露，可按需限制/扩展真值目标的距离范围。

### usv_interfaces
- 统一的消息/服务/动作定义，覆盖 GlobalTrack、VisionDetection、AISTrack、NavRadarTarget、MmwaveTarget、VesselState 等。
- `src/usv_interfaces/include/usv_interfaces/topics.hpp` 与 `src/usv_interfaces/usv_interfaces/topics.py` 暴露命名常量，避免硬编码话题。

## 数据流拓扑

下图展示了真值节点与四个模拟节点之间的话题连接关系（详见下一节的节点对比表）：

```mermaid
flowchart LR
    GT[ground_truth_node\n/sim/ground_truth] --> VISION(sim_vision_node)
    GT --> AIS(sim_ais_node)
    GT --> NAV(sim_nav_radar_node)
    GT --> MMWAVE(sim_mmwave_node)

    VISION -->|/vision/detections| VisionTopic[/VisionDetectionArray/]
    VISION -->|/vision/markers| VisionMarkers[/MarkerArray/]

    AIS -->|/ais/tracks| AISTopic[/AISTrackArray/]
    AIS -->|/ais/markers| AISMarkers[/MarkerArray/]

    NAV -->|/nav_radar/targets| NavTopic[/NavRadarTargetArray/]
    NAV -->|/nav_radar/markers| NavMarkers[/MarkerArray/]

    MMWAVE -->|/mmwave/targets| MmwaveTopic[/MmwaveTargetArray/]
    MMWAVE -->|/mmwave/markers| MmwaveMarkers[/MarkerArray/]
```

## 构建与运行

1. 准备 ROS 2 工作区并拉取仓库：
   ```bash
   mkdir -p ~/usv_ws/src && cd ~/usv_ws/src
   ln -s /home/cczh/temp-code/ground_truth_sim .
   ```
2. 构建（假设已安装系统依赖并 source `/opt/ros/<distro>/setup.bash`）：
   ```bash
   cd ~/usv_ws
   colcon build --packages-select usv_interfaces ground_truth_sim percision_sim
   source install/setup.bash
   ```
3. 一键启动（含静态 TF + ground_truth_node + 可选仿真节点 + RViz）：
   ```bash
   ros2 launch ground_truth_sim ground_truth_sim.launch.py \
     start_vision_node:=true start_ais_node:=true \
     start_nav_radar_node:=true start_mmwave_node:=true
   ```
4. 独立运行任意仿真节点，用统一参数文件：
   ```bash
   ros2 run percision_sim sim_nav_radar_node --ros-args \
     --params-file $(ros2 pkg prefix percision_sim)/share/percision_sim/config/percision_sim_params.yaml
   ```

### 一键脚本

仓库提供 `scripts/run_full_sim.sh`，可在已 source 系统 ROS 2 环境后直接运行，实现“清理 -> 构建 -> source -> 启动全部仿真”的自动化流程：

```bash
./scripts/run_full_sim.sh
```

脚本默认启用四个传感器模拟节点，可通过编辑脚本或在命令行追加 `--` 后的 `ros2 launch` 参数来自定义启动行为。

若只需“构建 + multi_sensor_sim 多传感器 launch”，可使用新脚本：

```bash
./scripts/run_multi_sensor_sim.sh [额外 ros2 launch 参数]
```

该脚本会先删除工作区根目录下的 `build/`、`install/`、`log/` 再执行 `colcon build --packages-select usv_interfaces ground_truth_sim percision_sim`，随后 source `install/setup.bash` 并调用 `ros2 launch percision_sim multi_sensor_sim.launch.py params_file:=<multi_sensor_params.yaml>`，默认 `use_rviz:=true` 并加载 `ground_truth_sim/rviz/ground_truth_view.rviz`，同时由 `static_tf_broadcaster` 发布 `parent_frame:=map -> child_frame:=base_link`。可通过附加参数（例如 `use_rviz:=false`、`rviz_config:=...`、`parent_frame:=odom`、`child_frame:=usv_base`）覆盖默认行为。

## 统一参数管理

- 真值：编辑 `src/sim/config/ground_truth_params.yaml` 或在 launch 时传入 `params_file:=<path>`。
- 传感器：`src/percision_sim/config/percision_sim_params.yaml` 以节点名分组（`sim_vision_node` / `sim_ais_node` / ...），可复制后按场景定制。
- 所有节点都支持以 `--ros-args -p key:=value` 方式覆盖参数，用于一次性调试。

## 传感器模拟对比

| 节点 | 可调参数示例 | 发布频率 | 噪声机制 | 噪声效果 | RViz 象征 |
| --- | --- | --- | --- | --- | --- |
| `sim_vision_node` | `fov_half_angle`、`sigma_angle`、`distance_noise_offset/scale`、`camera_id`/`class_*` | 50 Hz（随真值定时器） | 在极坐标上对角度/距离加入高斯噪声并按视场裁剪 | 方位 ±0.02 rad、距离随平方增长，远距目标置信度下降 | 蓝色球体按尺寸缩放 |
| `sim_ais_node` | `delay_sec`、`timer_period`、`queue_max`、`ship_name_prefix`、`text_height` | 每 0.2 s 检查队列，输出滞后 ≥ `delay_sec` | FIFO 延迟队列，强制保持旧时间戳 | 仅时间轴被“拉长”，空间信息保持真值 | 紫色 TEXT Marker 显示 MMSI |
| `sim_nav_radar_node` | `min_period`、`noise_std`、`area_jitter`、`marker_height` | ≥1 Hz（由 `min_period` 控制） | XY 位置加入 5 m 级高斯噪声，面积随机 ±10% | 位置呈大片抖动，面积读数随波动跳变 | 半透明黄色贴地方块 |
| `sim_mmwave_node` | `radial_noise_std`、`angle_noise_std`、`velocity_noise_std`、`size_jitter`、`snr_min/max`、`cylinder_height` | 与真值同步（默认 50 Hz） | 将目标投到极坐标后对距离/角度/速度施加高斯噪声 | 距离 ±0.5 m、角度 ±0.08 rad、速度 ±0.1 m/s，尺寸 ±20% | 绿色圆柱 + 速度箭头 |

## 关键话题（片段）

| 话题 | 类型 | 生产者 |
| --- | --- | --- |
| `/sim/ground_truth` | `usv_interfaces/msg/GlobalTrackArray` | `ground_truth_node` |
| `/sim/ground_truth_markers` | `visualization_msgs/msg/MarkerArray` | `ground_truth_node` |
| `/vision/detections` | `usv_interfaces/msg/VisionDetectionArray` | `sim_vision_node` |
| `/ais/tracks` | `usv_interfaces/msg/AISTrackArray` | `sim_ais_node` |
| `/nav_radar/targets` | `usv_interfaces/msg/NavRadarTargetArray` | `sim_nav_radar_node` |
| `/mmwave/targets` | `usv_interfaces/msg/MmwaveTargetArray` | `sim_mmwave_node` |

更多接口定义请参考 `usv_interfaces/msg/*.msg` 与 README。

## 许可证

所有子包均采用 Apache-2.0 许可证，欢迎在保持版权声明的前提下拓展仿真节点或集成其他感知模块。
