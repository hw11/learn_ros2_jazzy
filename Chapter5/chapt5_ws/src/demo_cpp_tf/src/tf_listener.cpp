#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"  // 提供消息接口
#include "tf2/LinearMath/Quaternion.h"  // 提供 tf2::Quaternion 类
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"  // 提供消息类型转换函数
#include "tf2_ros/transform_listener.h"  // 提供静态坐标广播器类
#include "tf2_ros/buffer.h" 
#include "tf2/utils.h" //四元数->欧拉角
#include "chrono"
using namespace std::chrono_literals;

class TFListener : public rclcpp::Node {
 public:
 TFListener() : Node("tf_listener") {
    // 创建静态广播发发布器并发布
    buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    listener_ = std::make_shared<tf2_ros::TransformListener>(*buffer_,this);
    timer_ = this->create_wall_timer(100ms,std::bind(&TFListener::getTransform,this));
    
  }
  void getTransform() {
    //到buffer查询坐标关系
    try{
        const auto transform = buffer_->lookupTransform("base_link","target_point",
            this->get_clock()->now(),rclcpp::Duration::from_seconds(1.0f));
        // 获取查询结果
        auto translation = transform.transform.translation;
        auto rotation = transform.transform.rotation;
        double y,p,r;
        tf2::getEulerYPR(rotation,y,p,r);
        RCLCPP_INFO(get_logger(),"平移：%f,%f,%f",translation.x,translation.y,translation.z);
        RCLCPP_INFO(get_logger(),"旋转%f,%f,%f",y,p,r);
        }
    catch(const std::exception& e){
        RCLCPP_WARN(get_logger(),"%s",e.what());
    }
  }
//   void publish_tf() {
//     geometry_msgs::msg::TransformStamped transform;
//     transform.header.stamp = this->get_clock()->now();
//     transform.header.frame_id = "map";
//     transform.child_frame_id = "target_point";
//     transform.transform.translation.x = 2.0;
//     transform.transform.translation.y = 3.0;
//     transform.transform.translation.z = 0.0;
//     tf2::Quaternion quat;
//     quat.setRPY(0, 0, 30 * M_PI / 180.0);  // 弧度制欧拉角转四元数
//     transform.transform.rotation = tf2::toMsg(quat);  // 转成消息接口类型
//     listener_->sendTransform(transform);
//   }

 private:
    std::shared_ptr<tf2_ros::Buffer> buffer_;
    std::shared_ptr<tf2_ros::TransformListener> listener_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<TFListener>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}