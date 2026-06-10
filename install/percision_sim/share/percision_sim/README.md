# percision_sim

`percision_sim` 提供 ROS 2 Python 传感器模拟节点：

- `sim_vision_node`：根据 `/sim/ground_truth` 上的 `usv_interfaces/msg/GlobalTrackArray` 生成视觉检测。
- `sim_ais_node`：以 3 秒以上延迟重播 AIS 报文，模拟低频高延迟广播链路。
- `sim_nav_radar_node`：以 1 Hz 周期输出导航雷达目标，具备大噪声、广域扫描特性。
- `sim_mmwave_node`：模拟 4D 毫米波雷达，具备高精度测距测速与较大的测角噪声。

`sim_vision_node` 节点会输出：

- `/vision/detections` (`usv_interfaces/msg/VisionDetectionArray`)：每个目标的距离、方位、尺寸与置信度。
- `/vision/markers` (`visualization_msgs/msg/MarkerArray`)：蓝色球体，可在 RViz 中查看摄像头检测。

## 构建

本包依赖 `usv_interfaces` 消息定义和 Python `numpy`。与 `ground_truth_sim` 位于同一工作区时，可一起构建：

```bash
colcon build --packages-select usv_interfaces ground_truth_sim percision_sim
source install/setup.bash
```

## 运行

### 视觉节点

```bash
ros2 run percision_sim sim_vision_node
```

常用参数（可通过 `--ros-args -p 参数:=值` 或 YAML 配置）：

| 参数 | 默认值 | 说明 |
| --- | --- | --- |
| `input_topic` | `/sim/ground_truth` | 来源真值话题 |
| `detection_topic` | `/vision/detections` | 检测结果输出 |
| `marker_topic` | `/vision/markers` | RViz Marker 话题 |
| `frame_id` | `base_link` | Marker/Detections 坐标系 |
| `camera_id` | `front` | 摄像头 ID |
| `camera_yaw` | `0.0` | 摄像头相对于 `frame_id` 的偏航角（弧度，右旋为正） |
| `class_name` | `ship` | 检测类别字符串 |
| `class_id` | `1` | 检测类别 ID |
| `fov_half_angle` | `π/4` | 可视域半角（弧度） |
| `sigma_angle` | `0.02` | 方位角噪声标准差 |
| `distance_noise_offset` | `0.05` | 距离测量噪声基准 |
| `distance_noise_scale` | `0.0005` | 距离噪声随距离平方的系数 |
| `publish_rate_hz` | `0.0` | 发布频率限制（Hz，0 表示随真值话题同步） |

该节点会根据距离自动衰减置信度，并在 RViz 中显示蓝色球体辅助可视化；若当前帧视场内无目标，仍会发布 header/output_stamp 完整的空 `VisionDetectionArray`，便于下游保持固定节拍。

#### 多相机示例

可运行多份 `sim_vision_node` 实例模拟前/后/左/右四个摄像头，只需为每个实例指定唯一的 `camera_id`、输出话题以及与安装方向一致的 `camera_yaw`。例如：

```bash
# 前后左右四个摄像头（示例）
ros2 run percision_sim sim_vision_node --ros-args \
	-p camera_id:=front -p detection_topic:=/vision/front/detections -p marker_topic:=/vision/front/markers -p camera_yaw:=0.0 &
ros2 run percision_sim sim_vision_node --ros-args \
	-p camera_id:=right -p detection_topic:=/vision/right/detections -p marker_topic:=/vision/right/markers -p camera_yaw:=-1.5708 &
ros2 run percision_sim sim_vision_node --ros-args \
	-p camera_id:=rear -p detection_topic:=/vision/rear/detections -p marker_topic:=/vision/rear/markers -p camera_yaw:=3.1416 &
ros2 run percision_sim sim_vision_node --ros-args \
	-p camera_id:=left -p detection_topic:=/vision/left/detections -p marker_topic:=/vision/left/markers -p camera_yaw:=1.5708 &
```

也可以在 launch/YAML 中为不同摄像头实例化节点，确保每个检测话题保持唯一，从而在融合端区分数据源。

### AIS 节点

```bash
ros2 run percision_sim sim_ais_node
```

该节点维持一个延迟队列，对每个真值快照至少滞后 3 秒才发布，且只转发 `is_ais_matched == true` 的目标，同时使用 TEXT Marker 在 RViz 显示紫色标注。

| 参数 | 默认值 | 说明 |
| --- | --- | --- |
| `input_topic` | `/sim/ground_truth` | 真值输入话题 |
| `ais_topic` | `/ais/tracks` | AIS 报文输出话题（`usv_interfaces/msg/AISTrackArray`） |
| `marker_topic` | `/ais/markers` | AIS 文本 Marker 输出 |
| `delay_sec` | `3.0` | 延迟队列处理阈值（秒） |
| `timer_period` | `0.2` | 队列检查周期（秒） |
| `ship_name_prefix` | `AIS-` | 缺省船名前缀，最终文本为 `prefix + MMSI` |
| `frame_id` | `base_link` | 当真值头部 frame 为空时使用的 Frame ID |
| `queue_max` | `300` | 队列最大缓存条目，溢出时丢弃最旧数据 |
| `text_height` | `1.5` | RViz TEXT Marker 高度（米） |

发布的 `AISTrackArray.header.stamp` 始终沿用 3 秒前的真值时间戳，以便融合算法识别旧数据；坐标、速度、航向直接采用真值，无额外噪声。

### 导航雷达节点

```bash
ros2 run percision_sim sim_nav_radar_node
```

节点会对 `/sim/ground_truth` 的真值进行 1 Hz 取样，每次处理都会对位置加入标准差为 5 m 的高斯噪声，并估算面积与贴地 Marker 以模拟雷达回波。

| 参数 | 默认值 | 说明 |
| --- | --- | --- |
| `input_topic` | `/sim/ground_truth` | 真值输入话题 |
| `target_topic` | `/nav_radar/targets` | 导航雷达目标输出（`usv_interfaces/msg/NavRadarTargetArray`） |
| `marker_topic` | `/nav_radar/markers` | RViz Marker 话题（黄色贴地 CUBE） |
| `frame_id` | `base_link` | Frame ID 兜底值 |
| `min_period` | `1.0` | 最短处理周期（秒），用于模拟 1 Hz 扫描 |
| `noise_std` | `5.0` | 位置噪声标准差（米） |
| `area_jitter` | `0.1` | 面积估计的±波动幅度 |
| `marker_height` | `0.1` | Marker 厚度（米） |

输出目标的速度直接复用真值，面积为 `size_w * size_l` 并加入 ±10% 随机波动；Marker 颜色固定为半透明黄色以突出雷达覆盖区域。

### 4D 毫米波节点

```bash
ros2 run percision_sim sim_mmwave_node
```

节点将真值投影到极坐标后注入距离/角度噪声，再回到笛卡尔坐标；速度仅增加 0.1 m/s 级别的高斯噪声，`size_w/size_l` 允许 ±20% 波动，同时生成绿色圆柱与箭头 Marker 表达聚类中心与速度矢量。可配置 `radar_yaw` 与 `fov_half_angle`（默认 120° 视场）来模拟多个指向不同扇区的毫米波雷达；若当前视场无目标，节点仍会发布空 `MmwaveTargetArray` 以及 `DELETEALL` Marker 刷新，以便下游保持定频输入。

| 参数 | 默认值 | 说明 |
| --- | --- | --- |
| `input_topic` | `/sim/ground_truth` | 真值输入话题 |
| `target_topic` | `/mmwave/targets` | 毫米波目标输出（`usv_interfaces/msg/MmwaveTargetArray`） |
| `marker_topic` | `/mmwave/markers` | Marker 输出话题（圆柱 + 速度箭头） |
| `frame_id` | `base_link` | 兜底 Frame ID |
| `radar_id` | `mmwave_front` | 雷达实例标识，写入 `MmwaveTarget.radar_id` |
| `radar_yaw` | `0.0` | 雷达相对 `frame_id` 的偏航角（弧度，右旋为正） |
| `fov_half_angle` | `1.047` | 视场半角（弧度），总 FoV ≈ 120° |
| `radial_noise_std` | `0.5` | 距离噪声标准差（米） |
| `angle_noise_std` | `0.08` | 方位角噪声标准差（弧度） |
| `velocity_noise_std` | `0.1` | 速度噪声标准差（m/s） |
| `size_jitter` | `0.2` | 宽/长的随机波动比例 |
| `motion_speed_threshold_m_s` | `0.3` | 速度低于此阈值时 `objmotion_status=0`（静止） |
| `cylinder_height` | `1.0` | 圆柱 Marker 高度（米） |
| `publish_rate_hz` | `0.0` | 输出频率限制（Hz，0 表示与真值同步） |

圆柱颜色设为绿色半透明（G=1.0，A=0.8），箭头从 `(x', y')` 指向 `(x' + v_x, y' + v_y)`，用于在 RViz 中直观展示多普勒速度。

#### 多雷达示例

可一次运行多份 `sim_mmwave_node` 来覆盖 360°：

```bash
ros2 run percision_sim sim_mmwave_node --ros-args \
	-p radar_id:=mmwave_front -p target_topic:=/mmwave/front/targets -p marker_topic:=/mmwave/front/markers -p radar_yaw:=0.0 &
ros2 run percision_sim sim_mmwave_node --ros-args \
	-p radar_id:=mmwave_starboard -p target_topic:=/mmwave/starboard/targets -p marker_topic:=/mmwave/starboard/markers -p radar_yaw:=-1.5708 &
ros2 run percision_sim sim_mmwave_node --ros-args \
	-p radar_id:=mmwave_rear -p target_topic:=/mmwave/rear/targets -p marker_topic:=/mmwave/rear/markers -p radar_yaw:=3.1416 &
ros2 run percision_sim sim_mmwave_node --ros-args \
	-p radar_id:=mmwave_port -p target_topic:=/mmwave/port/targets -p marker_topic:=/mmwave/port/markers -p radar_yaw:=1.5708 &
```

Launch 文件中同样可以通过参数字典为每个实例指定独立话题和 FoV。

### 单路传感器 launch（依赖真值）

在 **已运行** `ground_truth_sim.launch.py`（或任意发布 `/sim/ground_truth` 的节点）后：

```bash
ros2 launch percision_sim sensors_sim.launch.py \
	params_file:=$(ros2 pkg prefix percision_sim)/share/percision_sim/config/percision_sim_params.yaml
```

用 `start_vision_node` / `start_ais_node` / `start_nav_radar_node` / `start_mmwave_node`（默认除 AIS 外为 `true`）按需开关四个 `sim_*` 节点。

### 四视觉 + 四毫米波 launch

`launch/multi_sensor_sim.launch.py` 会根据 `config/multi_sensor_params.yaml` 同时启动：

- 4× `sim_vision_node`（前/后/左/右，`fov_half_angle=45°`，`publish_rate_hz=25`）
- 4× `sim_mmwave_node`（前/后/左/右，`fov_half_angle=60°`，`publish_rate_hz=15`）

**不**再包含 `ground_truth_node` 或静态 TF；请先启动 `ground_truth_sim.launch.py`（建议 `use_rviz:=false`），再启动本 launch。各节点加载同一 YAML，按节点名分组（例如 `/vision/front/detections`、`/mmwave/left/targets`）。后方毫米波 `frame_id` 与静态 TF 中的 `mmwave_back_link` 对齐。

```bash
# 终端 1
ros2 launch ground_truth_sim ground_truth_sim.launch.py use_rviz:=false

# 终端 2
ros2 launch percision_sim multi_sensor_sim.launch.py \
	params_file:=$(ros2 pkg prefix percision_sim)/share/percision_sim/config/multi_sensor_params.yaml
```

也可使用仓库脚本 `./scripts/run_multi_sensor_sim.sh`（后台自动拉起真值）。通过 `params_file` 可替换为自定义 YAML。

## 参数 YAML

仓库提供统一的参数文件 `config/percision_sim_params.yaml`，安装后路径为：

```
$(ros2 pkg prefix percision_sim)/share/percision_sim/config/percision_sim_params.yaml
```

任意节点都可以通过 `--ros-args --params-file <file>` (或在 launch 中传入 `parameters=[...params_file...]`) 载入该配置。文件内按照节点名分组，覆盖了 README 上述所有参数：

- `sim_vision_node`: 话题 (`input_topic`/`detection_topic`/`marker_topic`)、视场限制与距离/角度噪声 (`fov_half_angle`, `sigma_angle`, `distance_noise_*`)、摄像头姿态 (`frame_id`, `camera_yaw`) 以及识别类别 (`camera_id`, `class_name`, `class_id`)、发布频率 (`publish_rate_hz`)。
- `sim_ais_node`: 延迟队列与输出 (`delay_sec`, `timer_period`, `queue_max`)、AIS 文本标签 (`ship_name_prefix`, `text_height`) 以及输入/输出话题。
- `sim_nav_radar_node`: 1 Hz 周期 (`min_period`)、定位噪声 (`noise_std`)、面积波动 (`area_jitter`) 与 Marker 厚度 (`marker_height`)。
- `sim_mmwave_node`: 雷达姿态 (`frame_id`, `radar_id`, `radar_yaw`)、视场 (`fov_half_angle`)、极坐标/多普勒噪声 (`radial_noise_std`, `angle_noise_std`, `velocity_noise_std`)、尺寸波动 (`size_jitter`)、动静判定 (`motion_speed_threshold_m_s`)、圆柱高度 (`cylinder_height`) 以及输出频率 (`publish_rate_hz`)。

若需自定义参数，可复制该 YAML，调整对应节点下的 `ros__parameters` 值，再在运行/launch 时指定新的文件。
