import rclpy
from rclpy.node import Node
from autopatrol_interfaces.srv import SpeechText
import espeakng

class Speaker(Node):
    def __init__(self, node_name='speaker_node'):
        super().__init__(node_name)
        self.service = self.create_service(SpeechText, 'speak_text', self.speak_text_callback)
        self.speaker = espeakng.Speaker()
        self.speaker.voice = 'en'
    
    def speak_text_callback(self, request, response):
        self.get_logger().info(f"Received text to speak: {request.text}")
        self.speaker.say(request.text)
        self.speaker.wait()
        response.result = True
        return response
    
def main():
    rclpy.init()
    node = Speaker('speaker')
    rclpy.spin(node)
    rclpy.shutdown()
