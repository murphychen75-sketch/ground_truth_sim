from setuptools import find_packages
from setuptools import setup

setup(
    name='usv_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('usv_interfaces', 'usv_interfaces.*')),
)
