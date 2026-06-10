from setuptools import setup

package_name = "percision_sim"

setup(
    name=package_name,
    version="0.1.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/percision_sim"]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name, ["README.md"]),
        ("share/" + package_name + "/config", [
            "config/percision_sim_params.yaml",
            "config/multi_sensor_params.yaml",
            "config/three_vision_one_mmwave_params.yaml",
        ]),
        (
            "share/" + package_name + "/launch",
            [
                "launch/sensors_sim.launch.py",
                "launch/multi_sensor_sim.launch.py",
                "launch/three_sensor_sim.launch.py",
            ],
        ),
    ],
    install_requires=["setuptools", "numpy"],
    zip_safe=True,
    maintainer="USV Dev",
    maintainer_email="usv@example.com",
    description="Vision detection simulator driven by USV ground truth tracks",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "sim_vision_node = percision_sim.sim_vision_node:main",
            "sim_ais_node = percision_sim.sim_ais_node:main",
            "sim_nav_radar_node = percision_sim.sim_nav_radar_node:main",
            "sim_mmwave_node = percision_sim.sim_mmwave_node:main",
        ],
    },
)
