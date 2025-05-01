# setup.py   in  src/isolette_py_pkg

from setuptools import find_packages, setup

package_name = 'isolette_py_pkg'

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
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_exe = isolette_py_pkg.base_code.thermostat_regulate_temperature_manage_regulator_interface_mrit_runner:main",
            "thermostat_regulate_temperature_manage_heat_source_mhst_exe = isolette_py_pkg.base_code.thermostat_regulate_temperature_manage_heat_source_mhst_runner:main",
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe = isolette_py_pkg.base_code.thermostat_regulate_temperature_manage_regulator_mode_mrmt_runner:main",
            "thermostat_monitor_temperature_manage_alarm_mat_exe = isolette_py_pkg.base_code.thermostat_monitor_temperature_manage_alarm_mat_runner:main",
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_exe = isolette_py_pkg.base_code.thermostat_monitor_temperature_manage_monitor_interface_mmit_runner:main",
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe = isolette_py_pkg.base_code.thermostat_monitor_temperature_manage_monitor_mode_mmmt_runner:main",
            "operator_interface_oip_oit_exe = isolette_py_pkg.base_code.operator_interface_oip_oit_runner:main",
            "temperature_sensor_cpi_thermostat_exe = isolette_py_pkg.base_code.temperature_sensor_cpi_thermostat_runner:main",
            "heat_source_cpi_heat_controller_exe = isolette_py_pkg.base_code.heat_source_cpi_heat_controller_runner:main"
        ],
    },
)
