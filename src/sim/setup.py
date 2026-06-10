from setuptools import setup

package_name = "ground_truth_sim"

setup(
    name=package_name,
    version="0.1.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/ground_truth_sim"]),
        ("share/" + package_name, ["package.xml"]),
        (
            "share/" + package_name + "/rviz",
            [
                "rviz/ground_truth_view.rviz",
                "rviz/ground_truth_only.rviz",
                "rviz/three_sensor_fusion_view.rviz",
            ],
        ),
        (
            "share/" + package_name + "/config",
            [
                "config/ground_truth_params.yaml",
                "config/range_overlay_params.yaml",
                "config/three_sensor_overlay_params.yaml",
            ],
        ),
        (
            "share/" + package_name + "/launch",
            [
                "launch/ground_truth_sim.launch.py",
                "launch/full_stack_sim.launch.py",
                "launch/three_sensor_fusion_sim.launch.py",
            ],
        ),
    ],
    install_requires=["setuptools", "numpy"],
    zip_safe=True,
    maintainer="USV Dev",
    maintainer_email="usv@example.com",
    description="Ground truth generator with RViz visualization for USV simulations",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "ground_truth_node = ground_truth_sim.ground_truth_node:main",
            "static_tf_broadcaster = ground_truth_sim.static_tf_broadcaster:main",
            "range_overlay_node = ground_truth_sim.range_overlay_node:main",
        ],
    },
)
