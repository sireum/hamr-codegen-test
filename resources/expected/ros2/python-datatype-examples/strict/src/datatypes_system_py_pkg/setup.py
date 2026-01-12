# setup.py   in  src/datatypes_system_py_pkg

from setuptools import find_packages, setup

package_name = 'datatypes_system_py_pkg'

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
            "producer_producer_exe = datatypes_system_py_pkg.base_code.producer_producer_runner:main",
            "consumer_consumer_exe = datatypes_system_py_pkg.base_code.consumer_consumer_runner:main"
        ],
    },
)
