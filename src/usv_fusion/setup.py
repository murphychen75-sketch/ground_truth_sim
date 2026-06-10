from setuptools import setup

package_name = "usv_fusion"

setup(
    name=package_name,
    version="0.1.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml", "README.md"]),
        ("share/" + package_name + "/config", ["config/fusion_params.yaml"]),
        ("share/" + package_name + "/launch", ["launch/fusion.launch.py"]),
    ],
    install_requires=["setuptools", "numpy", "scipy"],
    zip_safe=True,
    maintainer="USV Dev",
    maintainer_email="usv@example.com",
    description="Vision and mmWave fusion for USV",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "sensor_fusion_node = usv_fusion.sensor_fusion_node:main",
        ],
    },
)
