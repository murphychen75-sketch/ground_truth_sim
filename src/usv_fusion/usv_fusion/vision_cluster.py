"""Cross-camera vision observation clustering (extensible via ClusterOptions)."""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import List, Sequence

from usv_fusion.association_fusion import VisionObservation


@dataclass
class ClusterOptions:
    """Parameters for cluster_vision_observations; extend with new fields for richer merging rules."""

    max_distance_m: float = 8.0
    allow_same_camera_in_cluster: bool = False
    min_confidence: float = 0.0


def cluster_vision_observations(
    observations: Sequence[VisionObservation],
    options: ClusterOptions | None = None,
) -> List[VisionObservation]:
    """Merge observations from different cameras that fall within a planar distance gate.

    Returns a list of synthetic VisionObservation rows (camera_id set to joined ids, confidence = max in cluster).
    """
    opts = options or ClusterOptions()
    obs_list = [o for o in observations if o.confidence >= opts.min_confidence]
    if len(obs_list) <= 1:
        return list(obs_list)

    n = len(obs_list)
    parent = list(range(n))

    def find(i: int) -> int:
        """Find union-find root for index i with path compression."""
        while parent[i] != i:
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    def union(a: int, b: int) -> None:
        """Union the sets containing indices a and b."""
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[rb] = ra

    for i in range(n):
        for j in range(i + 1, n):
            a, b = obs_list[i], obs_list[j]
            if not opts.allow_same_camera_in_cluster and a.camera_id == b.camera_id:
                continue
            dx = a.x - b.x
            dy = a.y - b.y
            if (dx * dx + dy * dy) ** 0.5 <= opts.max_distance_m:
                union(i, j)

    clusters: dict[int, List[int]] = {}
    for i in range(n):
        r = find(i)
        clusters.setdefault(r, []).append(i)

    merged: List[VisionObservation] = []
    for _root, idxs in clusters.items():
        members = [obs_list[k] for k in idxs]
        w_sum = sum(m.confidence for m in members)
        if w_sum < 1e-9:
            w_sum = 1.0
        x = sum(m.x * m.confidence for m in members) / w_sum
        y = sum(m.y * m.confidence for m in members) / w_sum
        size_w = max(m.size_w for m in members)
        size_h = max(m.size_h for m in members)
        conf = max(m.confidence for m in members)
        cids = sorted({m.camera_id for m in members})
        cam_label = ",".join(cids) if cids else "cluster"
        merged.append(
            VisionObservation(
                x=x,
                y=y,
                size_w=size_w,
                size_h=size_h,
                confidence=conf,
                camera_id=cam_label,
            )
        )
    return merged
