from setuptools import setup

package_name = "usv_event_fusion"

setup(
    name=package_name,
    version="0.1.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml", "README.md"]),
        (
            "share/" + package_name + "/docs",
            ["docs/usv_event_fusion_algorithm_reference.md"],
        ),
        (
            "share/" + package_name + "/config",
            [
                "config/event_fusion_io.yaml",
                "config/event_fusion_algorithm.yaml",
                "config/event_fusion_params.yaml",
                "config/event_fusion_three_sensor_io.yaml",
            ],
        ),
        ("share/" + package_name + "/launch", ["launch/event_fusion.launch.py"]),
    ],
    install_requires=["setuptools", "numpy", "scipy"],
    zip_safe=True,
    maintainer="USV Dev",
    maintainer_email="usv@example.com",
    description="Event-driven multi-sensor fusion for USV",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "event_fusion_node = usv_event_fusion.event_fusion_node:main",
        ],
    },
)
