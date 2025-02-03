from setuptools import find_packages
from setuptools import setup

setup(
    name='building_control_cpp_pkg_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('building_control_cpp_pkg_interfaces', 'building_control_cpp_pkg_interfaces.*')),
)
