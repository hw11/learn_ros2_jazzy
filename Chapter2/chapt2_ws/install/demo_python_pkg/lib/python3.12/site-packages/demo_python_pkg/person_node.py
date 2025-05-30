import rclpy
from rclpy.node import Node
class PersonNode(Node):
    def __init__(self, node_name: str, name_value: str, age_value: int):
        super().__init__(node_name)
        print('PersonNode __init__ method has been called')
        self.name = name_value
        self.age = age_value

    def eat(self, food_name: str):
        """"
        method: eat
        """
        #print(f'{self.name},{self.age} years old, eat {food_name}')
        self.get_logger().info(f'{self.name},{self.age} years old, eat {food_name}')

def main():
    rclpy.init()
    node = PersonNode('person_node','Zhang San', 18)
    node.eat('egg')
    rclpy.spin(node)
    rclpy.shutdown()