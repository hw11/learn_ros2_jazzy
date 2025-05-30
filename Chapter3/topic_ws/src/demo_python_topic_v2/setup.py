from setuptools import find_packages, setup

package_name = 'demo_python_topic_v2'

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
    maintainer_email='honhe@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'novel_pub_node=demo_python_topic_v2.novel_pub_node:main',
            'novel_sub_node=demo_python_topic_v2.novel_sub_node:main',
        ],
    },
)
