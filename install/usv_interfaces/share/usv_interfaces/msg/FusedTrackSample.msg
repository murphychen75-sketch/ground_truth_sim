# Single kinematic sample (trajectory point, service response, or jsonl row).
builtin_interfaces/Time stamp
float64 t_sec              # wall-time seconds (same instant as stamp); useful for offline tools
float64 x
float64 y
float64 v_x
float64 v_y
float64[16] covariance     # 4x4 row-major for x, y, v_x, v_y; use zeros if unknown
