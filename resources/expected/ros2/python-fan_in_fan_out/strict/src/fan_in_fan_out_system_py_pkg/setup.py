# setup.py   in  src/fan_in_fan_out_system_py_pkg

from setuptools import find_packages, setup

package_name = 'fan_in_fan_out_system_py_pkg'

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
            "fanIn_producer1_exe = fan_in_fan_out_system_py_pkg.base_code.fanIn_producer1_runner:main",
            "fanIn_producer2_exe = fan_in_fan_out_system_py_pkg.base_code.fanIn_producer2_runner:main",
            "fanIn_consumer_exe = fan_in_fan_out_system_py_pkg.base_code.fanIn_consumer_runner:main",
            "fanOut_producer_exe = fan_in_fan_out_system_py_pkg.base_code.fanOut_producer_runner:main",
            "fanOut_consumer1_exe = fan_in_fan_out_system_py_pkg.base_code.fanOut_consumer1_runner:main",
            "fanOut_consumer2_exe = fan_in_fan_out_system_py_pkg.base_code.fanOut_consumer2_runner:main"
        ],
    },
)
