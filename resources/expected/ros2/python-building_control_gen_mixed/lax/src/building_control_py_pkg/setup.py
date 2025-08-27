# setup.py   in  src/building_control_py_pkg

from setuptools import find_packages, setup

package_name = 'building_control_py_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sireum',
    maintainer_email='sireum@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "tcp_tempSensor_exe = building_control_py_pkg.base_code.tcp_tempSensor_runner:main",
            "tcp_tempControl_exe = building_control_py_pkg.base_code.tcp_tempControl_runner:main",
            "tcp_fan_exe = building_control_py_pkg.base_code.tcp_fan_runner:main"
        ],
    },
)
