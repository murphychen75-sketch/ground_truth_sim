# usv_event_fusion

**事件驱动**多目标融合：单一**全局航迹表**、互斥锁保护融合流程；每次回调仅处理**一种模态**（视觉或毫米波，引擎内不混批）。

## 文件清单

```
usv_event_fusion/                 # ROS 2 ament_python 功能包根目录
├── package.xml                   # 包清单与依赖声明
├── setup.py                      # 安装规则：节点入口、config/launch/docs 拷贝
├── setup.cfg                     # setuptools 元数据
├── resource/
│   └── usv_event_fusion          # ament 包索引标记（空文件）
├── README.md                     # 本说明
├── config/                       # 节点参数（ROS params-file）
│   ├── event_fusion_io.yaml      # 话题、外参、发布接口
│   ├── event_fusion_algorithm.yaml  # 滤波/门控/关联/航迹逻辑
│   └── event_fusion_params.yaml  # 上述两文件合并（可选单文件加载）
├── docs/
│   └── usv_event_fusion_algorithm_reference.md  # 算法与数据流详细说明
├── launch/
│   └── event_fusion.launch.py    # 启动 event_fusion_node，默认加载 io + algorithm
├── test/
│   └── test_polar_and_metrics.py # 极坐标 EKF、像素宽度、关联度量单元测试
└── usv_event_fusion/             # Python 模块（与包名同目录）
    ├── __init__.py               # 包版本号
    ├── event_fusion_node.py      # ROS 2 节点：订阅/发布、参数、互斥与回调编排
    ├── fusion_engine.py          # 全局航迹表、单模态融合步（预测→关联→更新→新生）
    ├── track_state.py            # InternalTrack / TrackProfile / 发布用 TrackState
    ├── motion_model.py           # 平面 CV 预测与过程噪声 Q
    ├── filters.py                # 线性/极坐标 EKF 更新、马氏距离、JPDA 混合更新
    ├── sensor_models.py          # 相机/雷达到船体变换、极坐标测量、宽度投影与 R 缩放
    ├── association_contract.py   # 关联问题/结果数据类（匈牙利、JPDA 契约）
    ├── association.py            # 匈牙利分配与 coast 虚列
    ├── association_metrics.py    # 关联代价：运动学 + 宽度 + 类别门控
    └── jpda.py                   # 单帧 JPDA 假设枚举（预留，当前主路径用匈牙利）
```

| 路径 | 作用 |
| --- | --- |
| `event_fusion_node.py` | 对外 ROS 接口：读参数、建订阅/发布、视觉/雷达观测转换、调用 `FusionEngine`、生成快照/档案/Marker |
| `fusion_engine.py` | 融合核心：航迹表维护、按时间预测、分模态匈牙利关联、EKF 更新、暂态/确认与超时删除 |
| `track_state.py` | 航迹 A 态（均值/协方差）与 B 态剖面（尺寸 LPF、类别投票）数据结构 |
| `motion_model.py` | 常速模型状态转移 F 与过程噪声 Q |
| `filters.py` | EKF 更新与门控用新息/马氏距离；JPDA 概率加权更新（供后续扩展） |
| `sensor_models.py` | 传感器几何与测量噪声：机体坐标、极坐标 h(x)/H、视觉置信度缩放 R |
| `association_contract.py` | 门控后关联问题的统一输入/输出类型定义 |
| `association.py` | `scipy` 线性分配 + 未匹配航迹 coast 代价列 |
| `association_metrics.py` | 视觉/雷达关联代价矩阵元素（chi² 门 + 宽度 + 类别） |
| `jpda.py` | JPDA 可行假设计数与 beta 矩阵（超预算时回退匈牙利） |

构建产物（`build/`、`install/`、`__pycache__/`、`.pytest_cache/`）不在上表列出。

## 节点

| 可执行文件 | 说明 |
| --- | --- |
| `event_fusion_node` | 订阅 `vision_topics[]` 与 `mmwave_topic`；回调内执行预测 → 椭球门控 → 匈牙利 → EKF 更新；发布 `FusedSceneSnapshot`（仅已确认航迹）、档案目录与 RViz 轨迹；可选旧版 `GlobalTrackArray`。 |

## 启动

```bash
ros2 launch usv_event_fusion event_fusion.launch.py
```

默认加载 `config/event_fusion_io.yaml` + `config/event_fusion_algorithm.yaml`。单文件覆盖：

```bash
ros2 launch usv_event_fusion event_fusion.launch.py \
  params_file:=$(ros2 pkg prefix usv_event_fusion)/share/usv_event_fusion/config/event_fusion_params.yaml
```

## 参数文件

| 文件 | 内容 |
| --- | --- |
| [`config/event_fusion_io.yaml`](config/event_fusion_io.yaml) | 话题、坐标系、相机/雷达外参、发布接口 |
| [`config/event_fusion_algorithm.yaml`](config/event_fusion_algorithm.yaml) | 过程/测量噪声、门控、关联代价、航迹生命周期 |
| [`config/event_fusion_params.yaml`](config/event_fusion_params.yaml) | 上述两文件合并（单 `--params-file` 时使用） |

各参数含义见 YAML 内单行中文注释。

## RViz

轨迹话题默认 **`/fusion/track_markers`**（`MarkerArray`，命名空间 `fusion_history`，`LINE_STRIP`）。同一航迹至少需**两次**融合回调才会出现折线。全栈仿真 `ground_truth_view.rviz` 已配置「Fusion Track History」；自建 RViz 时请添加 `MarkerArray` 并订阅该话题。

## 关联概要

**匈牙利**一对一分配 + 椭球门控 + **coast 虚列**（未匹配航迹可滑行）。视觉宽度在**像素域**匹配（`profile_width_to_pixel_width`，需 `vision_focal_length_px`）；雷达宽度用物理 `size_w`（米）。B 态尺寸低通按**距离加权**（远目标更新更慢）。

## 文档

- **[融合算法参考](docs/usv_event_fusion_algorithm_reference.md)**：输入输出、处理步骤、关联与航迹维护
