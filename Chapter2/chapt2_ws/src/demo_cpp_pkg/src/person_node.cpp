#include "rclcpp/rclcpp.hpp"

class PersonNode : public rclcpp::Node
{
    private: 
        std::string name_;
        int age_;
    public:
        PersonNode(const std::string &node_name,const std::string &name,
            const int &age):Node(node_name) /*调用父类的构造函数，=super().__init__()*/
        {
            this->name_ = name;
            this->age_ = age;
        };

        void eat(const std::string &food_name)
        {
            RCLCPP_INFO(this->get_logger(),"I am %s, %d years old. I like to eat %s",this->name_.c_str(),
            this->age_,food_name.c_str());
        };
};

int main(int argc, char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<PersonNode>("person_node", "Zhang San", 18);
    RCLCPP_INFO(node->get_logger(),"hello, c++ node!");
    node->eat("fish ROS");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}