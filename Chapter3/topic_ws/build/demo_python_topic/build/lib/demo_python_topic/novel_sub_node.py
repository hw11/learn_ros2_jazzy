import espeakng
import rclpy
from rclpy.node import Node
import requests
from example_interfaces.msg import String
from queue import Queue
import threading
import time

class NovelSubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info(f'{node_name}，启动')
        self.novel_queue = Queue()
        self.novel_subscriber = self.create_subscription(String, 'novel', self.novel_callback, 10)
        self.speech_thread = threading.Thread(target=self.speaker_thread)
        self.speech_thread.start()

    def novel_callback(self,msg):
        self.novel_queue.put(msg.data)

    def speaker_thread(self):
        speaker = espeakng.Speaker()
        speaker.voice = 'zh'
        while rclpy.ok(): #检测当前ros上下文是否ok
            if self.novel_queue.qsize()>0:
                text = self.novel_queue.get()
                self.get_logger().info(f'朗读： {text}')
                speaker.say(text)
                speaker.wait()  # 等它说完
            else:
                # 让当前线程休眠1s
                time.sleep(1)

def main():
    rclpy.init()
    node = NovelSubNode('novel_pub')
    rclpy.spin(node)
    rclpy.shutdown()