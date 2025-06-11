from setuptools import find_packages, setup

package_name = 'learn_qos_py'

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
    maintainer='honhe',
    maintainer_email='1006727084@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'reliability_test = learn_qos_py.realiability_test:main',
            # 'durability_test = learn_qos_py.durability_test:main',
            # 'deadline_test = learn_qos_py.deadline_test:main',
            # 'lifespan_test = learn_qos_py.lifespan_test:main',
            # 'liveliness_test = learn_qos_py.liveliness_test:main',
        ],
    },
)
