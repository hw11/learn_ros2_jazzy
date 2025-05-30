#include <iostream>
#include <memory>

int main()
{
    auto p1 = std::make_shared<std::string>("This is a str."); //std::make_shared<数据类型/类>(参数)
    // 返回值，对应类的共享指针 std::shared_ptr<std::string>
    std::cout<<"reference number of p1: "<<p1.use_count() << "; address of pointing memory: "<<p1.get()<<std::endl;
    auto p2 = p1;
    std::cout<<"reference number of p1: "<<p1.use_count() << "; address of pointing memory: "<<p1.get()<<std::endl;
    std::cout<<"reference number of p2: "<<p2.use_count() << "; address of pointing memory: "<<p2.get()<<std::endl;
    
    p1.reset(); //release reference
    std::cout<<"reference number of p1: "<<p1.use_count() << "; address of pointing memory: "<<p1.get()<<std::endl;
    std::cout<<"reference number of p2: "<<p2.use_count() << "; address of pointing memory: "<<p2.get()<<std::endl;

    std::cout<<"data of the pointing memory of p2: "<<p2->c_str()<<std::endl;

    return 0;
}