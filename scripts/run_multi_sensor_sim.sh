#!/usr/bin/env bash
# Build and launch multi-sensor sim (4 vision + 4 mmWave). Ground truth must run first.
# Usage: ./scripts/run_multi_sensor_sim.sh [additional ros2 launch args for multi_sensor_sim]

set -euo pipefail

WORKSPACE_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$WORKSPACE_ROOT"

echo "[run_multi_sensor_sim] Removing previous build/install/log directories..."
rm -rf build install log

echo "[run_multi_sensor_sim] Building usv_interfaces, ground_truth_sim, percision_sim..."
colcon build --packages-select usv_interfaces ground_truth_sim percision_sim

echo "[run_multi_sensor_sim] Sourcing install/setup.bash..."
# shellcheck disable=SC1091
set +u
source "$WORKSPACE_ROOT/install/setup.bash"
set -u

cleanup() {
  if [[ -n "${GT_PID:-}" ]] && kill -0 "$GT_PID" 2>/dev/null; then
    echo "[run_multi_sensor_sim] Stopping ground_truth launch (pid $GT_PID)..."
    kill "$GT_PID" 2>/dev/null || true
    wait "$GT_PID" 2>/dev/null || true
  fi
}
trap cleanup EXIT

echo "[run_multi_sensor_sim] Starting ground_truth_sim (no RViz) in background..."
ros2 launch ground_truth_sim ground_truth_sim.launch.py use_rviz:=false &
GT_PID=$!

sleep 2

PARAMS_FILE="$(ros2 pkg prefix percision_sim)/share/percision_sim/config/multi_sensor_params.yaml"
echo "[run_multi_sensor_sim] Launching percision_sim multi_sensor_sim.launch.py with params ${PARAMS_FILE}"
ros2 launch percision_sim multi_sensor_sim.launch.py params_file:="$PARAMS_FILE" "$@"
