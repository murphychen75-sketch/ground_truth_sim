# usv_interfaces

此包为 USV（无人水面车辆）目标融合与控制系统提供统一的 ROS 2 接口定义：自定义消息（msg）、服务（srv）、动作（action）以及 C++/Python 的话题与 frame 常量。

目的：为感知、融合、控制与任务管理模块提供一致的数据契约，便于多语言节点互操作、快速集成与系统级联调。

---

## 主要内容

- 自定义消息（msg）：描述雷达、视觉、AIS、船舶状态、控制偏差等融合后或控制所需的数据结构。
- 服务（srv）：对设备（例如灯、泵）下发控制命令并获取执行结果。
- 动作（action）：异步任务接口（例如执行航点任务，提供实时 feedback 与最终 result）。
- C++ 与 Python 常量：统一的 topic/frame 名称定义，便于在节点中复用。

## 仓库结构（简要）

- `CMakeLists.txt`：ROS 2（ament）构建脚本，使用 `rosidl_generate_interfaces` 生成接口代码。
- `package.xml`：包元信息与依赖声明（`std_msgs`、`geometry_msgs`、`nav_msgs`、`builtin_interfaces` 等）。
- `msg/`：
  - `ControlDeviation.msg` — 控制偏差（横向/航向误差、目标/当前速度等）。
  - `VisionDetection.msg` — 视觉检测单目标（相机 id、角度、距离、横向宽度、高度、置信度）。
  - `VisionDetectionArray.msg` — 视觉检测集合（含 header 与 output_stamp）。
  - `MmwaveTarget.msg` — 4D 毫米波目标（雷达 ID、平面坐标、速度、尺寸、SNR）。
  - `MmwaveTargetArray.msg` — 毫米波目标数组（含 header）。
  - `NavRadarTarget.msg` — 导航雷达目标（平面坐标、速度、面积）。
  - `NavRadarTargetArray.msg` — 导航雷达目标数组（含 header）。
  - `AISTrack.msg` — AIS 跟踪条目（MMSI、船名、相对位置/速度、航向）。
  - `AISTrackArray.msg` — AIS 跟踪集合（含 header）。
  - `GlobalTrack.msg` — 融合后的全局轨迹（id、平面位姿、速度、尺寸、协方差、标签）。
  - `GlobalTrackArray.msg` — 全局轨迹集合（含 header）。
  - `VesselState.msg` — 船舶综合状态（GNSS/里程计/IMU 融合的 pose/twist、电池、姿态等）。
  - `VisionDetection.msg` — 视觉检测单目标（相机 id、角度、距离、横向宽度、高度、置信度）。
  - `OperationMode.msg` — 运行模式常量与当前模式字段。
- `srv/`：
  - `ControlDevice.srv` — 设备控制服务（请求 device_id/command/value，返回 success/message）。
- `action/`：
  - `ExecuteMission.action` — 执行任务的动作接口（goal/feedback/result）。
- `include/usv_interfaces/topics.hpp`：C++ 话题/frame 常量。
- `usv_interfaces/topics.py`：Python 话题/frame 常量（与 C++ 同步）。

- `msg/sensor_plugins/`：仿真与桥接插件（可选）
  - `gz_maritime_radar_plugin` — Gazebo 插件，发布 `gz.msgs.Float_V`（spokes）
  - `radar_gz_bridge` — 桥接器，将 `gz.msgs.Float_V` 转换为 `marine_sensor_msgs/RadarSector`（话题 `/sensors/radar/nav/sector`）


## 消息/服务/动作 快速参考

- ControlDeviation
  - 字段：header、cross_track_error、heading_error、distance_to_goal、target_speed、current_speed
  - 用途：控制器产生的偏差/误差信息，可用于闭环控制或监控。

- VisionDetection / VisionDetectionArray
  - 单体字段：camera_id、class_name、class_id、azimuth、distance_predict、size_w、size_h、confidence
  - Array：包含 `std_msgs/Header header`（采样时间）与 `builtin_interfaces/Time output_stamp`（处理完成时间）以及 `VisionDetection[] detections`。

- MmwaveTarget / MmwaveTargetArray
  - 单体字段：radar_id、x、y、v_x、v_y、size_w、size_l、size_h、snr
  - Array：包含 `std_msgs/Header header` 与 `MmwaveTarget[] targets`。

- NavRadarTarget / NavRadarTargetArray
  - 单体字段：x、y、v_x、v_y、area
  - Array：包含 `std_msgs/Header header` 与 `NavRadarTarget[] targets`。

- AISTrack / AISTrackArray
  - 单体字段：mmsi、ship_name、relative_x、relative_y、relative_v_x、relative_v_y、true_heading
  - Array：包含 `std_msgs/Header header` 与 `AISTrack[] tracks`。

- GlobalTrack / GlobalTrackArray
  - 单体字段（融合输出）：track_id、x、y、v_x、v_y、size_w、size_l、size_h、float64[16] covariance、is_dark_target、is_ais_matched、matched_mmsi
  - Array：包含 `std_msgs/Header header` 与 `GlobalTrack[] tracks`（融合时间戳，base_link 坐标系）。

- RadarSector
  - 消息类型：`marine_sensor_msgs/RadarSector`
  - 用途：海事雷达扇区/叶片数据（由 `/blueboat/radar/spokes` 经 `radar_gz_bridge` 映射到 `/sensors/radar/nav/sector`）

- VesselState
  - 字段：header、latitude、longitude、altitude、pose、velocity、roll/pitch/yaw、battery_*、leak_detected、cpu_temperature
  - 用途：融合后的本船状态，适用于控制、UI 与记录。

- OperationMode
  - 模式常量：MODE_MANUAL=0、MODE_AUTO_HEADING=1、MODE_SMART_PATH=2、MODE_AUTO_NAV=3
  - 字段：header、mode

- ControlDevice.srv
  - Request: device_id、command、value
  - Response: success、message

- ExecuteMission.action
  - Goal: mission_file_name、forbidden_zone_file、loop_execution
  - Feedback: current_task_name、current_waypoint_index、mission_progress、status_text
  - Result: success、message

### 消息字段详解

#### VisionDetection / VisionDetectionArray

| 字段 | 类型 | 说明 |
| --- | --- | --- |
| `camera_id` | `string` | 摄像头标识（如 `front`/`left`/`right`），单个摄像头覆盖约 90° 视场 |
| `class_name` | `string` | 目标类别名称，与视觉模型的标签一致 |
| `class_id` | `int32` | 目标类别 ID（与 `class_name` 对应的数值标签） |
| `azimuth` | `float64` | 目标相对该摄像头光心的水平方位角（弧度，右正） |
| `distance_predict` | `float64` | 单目预测的相对直线距离（米），<100 m 可信度高，>300 m 仅保留角度 |
| `size_w` / `size_h` | `float64` | 预测的目标物理宽度、可见高度（米），仅提供可视范围内的尺寸 |
| `confidence` | `float64` | 检测置信度（0~1），融合节点会按距离动态调节协方差 |

| VisionDetectionArray 字段 | 类型 | 说明 |
| --- | --- | --- |
| `header` | `std_msgs/Header` | 必须继承相机原始图像的时间戳与坐标系 |
| `output_stamp` | `builtin_interfaces/Time` | 算法输出该结果的系统时间，便于计算端到端延迟 |
| `detections` | `VisionDetection[]` | 当前帧的检测列表 |

> 当视场内无目标时，`detections` 列表可以为空，消费节点需接受空数组输入。

#### MmwaveTarget / MmwaveTargetArray（4D 毫米波）

| 字段 | 类型 | 说明 |
| --- | --- | --- |
| `radar_id` | `string` | 雷达实例标识（如 `front`/`right`），用于区分多雷达输出 |
| `x` / `y` | `float64` | 聚类中心相对坐标（米） |
| `v_x` / `v_y` | `float64` | 平面速度矢量（米/秒），可为绝对或相对速度 |
| `size_w` / `size_l` | `float64` | 点云聚类估算的宽度/长度（米） |
| `size_h` | `float64` | 点云聚类估算的高度（米），仅用于高度分类，不参与 EKF 追踪 |
| `snr` | `float64` | 信噪比，融合节点据此调节尺寸置信度 |

| MmwaveTargetArray 字段 | 类型 | 说明 |
| --- | --- | --- |
| `header` | `std_msgs/Header` | 毫米波雷达的时间戳与坐标系 |
| `targets` | `MmwaveTarget[]` | 当前扫描周期输出的所有 4D 雷达目标 |

#### NavRadarTarget / NavRadarTargetArray（导航雷达）

| 字段 | 类型 | 说明 |
| --- | --- | --- |
| `x` / `y` | `float64` | 相对平面坐标（米） |
| `v_x` / `v_y` | `float64` | 2D 速度矢量（米/秒） |
| `area` | `float64` | 目标 2D 投影面积估算（平方米） |

| NavRadarTargetArray 字段 | 类型 | 说明 |
| --- | --- | --- |
| `header` | `std_msgs/Header` | 导航雷达坐标系与时间戳 |
| `targets` | `NavRadarTarget[]` | 扫描周期内的所有雷达目标 |

#### AISTrack / AISTrackArray（AIS）

| 字段 | 类型 | 说明 |
| --- | --- | --- |
| `mmsi` | `uint32` | 船舶唯一识别码（Maritime Mobile Service Identity） |
| `ship_name` | `string` | 船名 |
| `relative_x` / `relative_y` | `float64` | 经上游解算后的相对本船坐标（米） |
| `relative_v_x` / `relative_v_y` | `float64` | 相对速度矢量（米/秒） |
| `true_heading` | `float64` | 真实艏向角（弧度） |

| AISTrackArray 字段 | 类型 | 说明 |
| --- | --- | --- |
| `header` | `std_msgs/Header` | AIS 报文时间戳 |
| `tracks` | `AISTrack[]` | 当前批次的 AIS 轨迹集合 |

#### GlobalTrack / GlobalTrackArray（融合输出）

| 字段 | 类型 | 说明 |
| --- | --- | --- |
| `track_id` | `uint32` | 融合中心分配的全局唯一 ID |
| `x` / `y` | `float64` | 融合后的平滑相对坐标（米） |
| `v_x` / `v_y` | `float64` | 融合后的平滑速度（米/秒） |
| `size_w` / `size_l` / `size_h` | `float64` | 综合估算的 3D 尺寸（宽/长/高，单位米） |
| `covariance` | `float64[16]` | 4×4 协方差矩阵，按 `(x, y, v_x, v_y)` 顺序铺平 |
| `is_dark_target` | `bool` | 是否为未匹配 AIS 的暗目标/可疑船只 |
| `is_ais_matched` | `bool` | 是否成功绑定 AIS |
| `matched_mmsi` | `uint32` | 若绑定成功，对应的 AIS MMSI |

| GlobalTrackArray 字段 | 类型 | 说明 |
| --- | --- | --- |
| `header` | `std_msgs/Header` | 融合时间戳，统一为 `base_link` 坐标系 |
| `tracks` | `GlobalTrack[]` | 同一时间内的全局轨迹列表 |

## 常量（C++ / Python）

统一话题与 frame 常量位于：

- C++：`include/usv_interfaces/topics.hpp`
- Python：`usv_interfaces/topics.py`

示例（部分）：

- `TOPIC_VESSEL_STATE = "/usv/state/vessel"`
- `TOPIC_CONTROL_DEVIATION = "/usv/control/deviation"`
- `TOPIC_SENSOR_GPS = "/sensors/gps/data"`

建议在节点中引用这些常量以避免硬编码字符串，便于统一管理与重映射。

## 构建与安装（ROS 2）

在 ROS 2 环境下（例如已 source `/opt/ros/<distro>/setup.bash`）：

```bash
# 从工作区根构建（若 package 在 workspace 中）
cd /home/cczh/USV_ROS
colcon build --packages-select usv_interfaces

# 构建完成后加载环境
source install/setup.bash
```

说明：`CMakeLists.txt` 已使用 `rosidl_generate_interfaces` 和 `ament_python_install_package`，构建将生成 C++/Python 绑定并安装 package。

## 使用示例（简要）

- Python 发布 `VesselState`（示意）：

```python
from rclpy.node import Node
from usv_interfaces.msg import VesselState
from usv_interfaces import topics

class StatePublisher(Node):
    def __init__(self):
        super().__init__('state_pub')
        self.pub = self.create_publisher(VesselState, topics.TOPIC_VESSEL_STATE, 10)
        # 填充消息并发布

```

- C++ 订阅 `ControlDeviation`（示意）：

```cpp
#include "rclcpp/rclcpp.hpp"
#include "usv_interfaces/msg/control_deviation.hpp"
#include "usv_interfaces/topics.hpp"

auto sub = node->create_subscription<usv_interfaces::msg::ControlDeviation>(
    usv_interfaces::TOPIC_CONTROL_DEVIATION, 10,
    [](const usv_interfaces::msg::ControlDeviation::SharedPtr msg){ /* 处理 */ });
```

- Python 调用 `ControlDevice` 服务（示意）：

```python
client = node.create_client(usv_interfaces.srv.ControlDevice, '/control/device')
req = usv_interfaces.srv.ControlDevice.Request()
req.device_id = "nav_light_left"
req.command = "ON"
req.value = 1.0
future = client.call_async(req)
```

关于 `ExecuteMission` action，请参考 ROS 2 的 action 客户端 API (`rclpy.action` / `rclcpp_action`) 获取完整范例。

## 测试与验证建议

- 为每个消息类型编写基本的发布/订阅测试（pytest + rclpy），验证序列化/字段正确性。
- 为 `ExecuteMission` 动作做集成测试（模拟伪执行器，检查 feedback/result）。
- 提供一个小型仿真 demo（将仿真传感器话题映射到本包的常量），用于端到端验证。

## 许可证与贡献

- 包版本（package.xml）：0.1.0
- 许可证：Apache-2.0

贡献指南：提交 PR 时请包含变更说明和最小可运行示例，修改消息时请考虑向后兼容或提供迁移说明。

## 后续建议（优先级）

1. 添加 `examples/`：包含 Python 与 C++ 的最小示例节点（publish/subscribe/service/action）。
2. 增加 CI：在 PR 中运行构建与简单通信测试（colcon build + pytest）。
3. 补充 `StandardDataTypes.md`，明确自定义消息和标准消息的映射与示例。
4. 添加文档生成流程（Sphinx 或其他）以产出在线 API 参考。

---

若需要，我可以另外：

- 在 `examples/` 下生成一个最小的 Python 发布者与订阅者示例。
- 为 README 添加更多示例截图或数据示例。

如果你希望我现在把 README 提交到仓库（已执行），我还可以同时创建示例并运行快速测试。
