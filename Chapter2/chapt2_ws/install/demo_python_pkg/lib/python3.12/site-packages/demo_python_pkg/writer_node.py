from demo_python_pkg.person_node import PersonNode
import rclpy
from rclpy.node import Node

class WriterNode(PersonNode):
    def __init__(self, node_name: str, name_value: str, age_value: int, book_name: str):
        super().__init__(node_name, name_value, age_value)
        self.book = book_name

def main():
    rclpy.init()
    node = WriterNode('writer_node', 'Zhang San', 20, 'ROS fish')
    node.eat('fish')
    print(f'write book: {node.book}')
    rclpy.spin(node)
    rclpy.shutdown()