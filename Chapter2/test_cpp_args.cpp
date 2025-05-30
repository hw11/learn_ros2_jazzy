#include "iostream"
int main(int argc, char** argv)
{
    std::cout<<"number of parameters = "<<argc<<std::endl;
    std::cout<<"name of program = "<<argv[0]<<std::endl;
    std::string arg1 = argv[1];
    if(arg1=="--help")
    {
        std::cout<<"this is help of program"<<std::endl;
    }
    return 0;
}