#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"  // 提供消息接口
#include "tf2/LinearMath/Quaternion.h"  // 提供 tf2::Quaternion 类
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"  // 提供消息类型转换函数
#include "tf2_ros/transform_broadcaster.h"  // 提供静态坐标广播器类
#include "chrono"
using namespace std::chrono_literals;

class TFBroadcaster : public rclcpp::Node {
 public:
  TFBroadcaster() : Node("static_tf_broadcaster") {
    // 创建静态广播发发布器并发布
    broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
    timer_ = this->create_wall_timer(100ms,std::bind(&TFBroadcaster::publish_tf,this));
  }

  void publish_tf() {
    geometry_msgs::msg::TransformStamped transform;
    transform.header.stamp = this->get_clock()->now();
    transform.header.frame_id = "map";
    transform.child_frame_id = "base_link";
    transform.transform.translation.x = 2.0;
    transform.transform.translation.y = 3.0;
    transform.transform.translation.z = 0.0;
    tf2::Quaternion quat;
    quat.setRPY(0, 0, 30 * M_PI / 180.0);  // 弧度制欧拉角转四元数
    transform.transform.rotation = tf2::toMsg(quat);  // 转成消息接口类型
    broadcaster_->sendTransform(transform);
  }

 private:
  std::shared_ptr<tf2_ros::TransformBroadcaster> broadcaster_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<TFBroadcaster>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}