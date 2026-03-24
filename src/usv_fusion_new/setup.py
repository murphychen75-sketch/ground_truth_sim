from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'usv_fusion_new'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # 将所有的 launch 文件安装到 share 目录下
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        # 将所有的 rviz 文件安装到 share 目录下
        (os.path.join('share', package_name, 'rviz'), glob('rviz/*.rviz')),
    ],
    install_requires=['setuptools', 'numpy', 'scipy', 'filterpy'],
    zip_safe=True,
    maintainer='cczh',
    maintainer_email='cczh@todo.todo',
    description='USV Multi-Sensor Hierarchical Fusion System',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # Level 1 局部融合节点注册入口
            'local_fusion_node = usv_fusion_new.local_fusion_node:main',
            # Level 2 全局融合节点注册入口
            'global_fusion_node = usv_fusion_new.global_fusion_node:main',
            # Level 3 辅助诊断可视化节点注册入口
            'global_viz_node = usv_fusion_new.global_viz_node:main',
        ],
    },
)
