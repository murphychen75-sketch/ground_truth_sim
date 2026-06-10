# usv_fusion（已弃用）

> **DEPRECATED**：请改用 **`usv_event_fusion`**（`event_fusion_node`）：事件驱动、单全局航迹表、互斥保护、单模态观测逐步更新。本包保留仅供对照，新工程勿依赖。

`usv_fusion` 提供 **多路视觉 + 4D 毫米波** 的多目标关联与 CV-EKF 融合：跨相机观测在 `vision_cluster.py` 聚类后，与雷达做匈牙利配对，轨迹管理器分配单调 `track_id`。

## 功能概览

| 组件 | 说明 |
| --- | --- |
| `sensor_fusion_node` | 多订阅 `vision_topics`；投影到 `base_link`；定时融合；发布 `FusedSceneSnapshot`、`FusedTargetCatalog`、`MarkerArray`；可选 legacy `GlobalTrackArray`；`history_dir` 非空时按 `target_<id>.jsonl` 落盘并开启 `get_target_history` 服务。 |
| `association_fusion.py` | 门控、雷达–视觉（聚类后）匈牙利、轨迹–量测匈牙利、CV/EKF；ROS 无关。 |
| `vision_cluster.py` | `cluster_vision_observations` + `ClusterOptions`，便于扩展更多聚类准则。 |
| `history_io.py` | jsonl 追加与按时间窗读取（供 service 使用）。 |

## 话题与服务

| 方向 | 名称 | 类型 |
| --- | --- | --- |
| 订阅 | `vision_topics[]` | `VisionDetectionArray` |
| 订阅 | `mmwave_topic` | `MmwaveTargetArray` |
| 发布 | `fusion_snapshot_topic`（默认 `/fusion/snapshot`） | `FusedSceneSnapshot` |
| 发布 | `fusion_catalog_topic`（默认 `/fusion/catalog`） | `FusedTargetCatalog` |
| 发布 | `fusion_markers_topic` | `MarkerArray` |
| 发布 | `fusion_tracks_topic`（仅当 `publish_legacy_global_track`） | `GlobalTrackArray` |
| 服务 | `get_target_history` | `usv_interfaces/srv/GetTargetHistory` |

常量见 [`usv_interfaces/topics.py`](../usv_interfaces/usv_interfaces/topics.py) 中 `TOPIC_FUSION_SNAPSHOT`、`TOPIC_FUSION_CATALOG` 等。

## 构建

新项目请构建 **`usv_event_fusion`**。若仍需对照本弃用包：

```bash
colcon build --packages-select usv_interfaces usv_event_fusion
# 可选：colcon build --packages-select usv_fusion
source install/setup.bash
```

## 运行

新项目：`ros2 launch usv_event_fusion event_fusion.launch.py`。旧命令（仅对照）：`ros2 launch usv_fusion fusion.launch.py`。

## 参数摘要

- **多相机**：`vision_topics`、`vision_camera_ids`、`vision_camera_yaws`、`vision_camera_mount_x/y`（数组长度与话题数一致；缺省项用 `default_camera_*` 填充）。
- **聚类**：`cluster_max_distance_m`、`cluster_allow_same_camera`。
- **快照 / 档案**：`fusion_snapshot_topic`、`fusion_catalog_topic`、`catalog_publish_hz`。
- **Legacy**：`publish_legacy_global_track`、`fusion_tracks_topic`。
- **落盘**：`history_dir`（空则禁用写文件；service 在无目录时返回 `status=2`）。
- **滤波**：`gating_m`、`gate_distance_m`、`position_std_*`、`process_noise_*` 等见 `config/fusion_params.yaml`。

完整列表以 [`config/fusion_params.yaml`](config/fusion_params.yaml) 为准。

## 许可证

Apache-2.0
