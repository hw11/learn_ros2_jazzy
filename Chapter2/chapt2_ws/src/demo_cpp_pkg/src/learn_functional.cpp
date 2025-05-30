#include <iostream>
#include <functional>

// free function
void save_with_free_fun(const std::string& file_name)
{
    std::cout << "调用了自由函数，保存:" << file_name << std::endl;
};

// member function
class FileSave
{
    private:
    /* data */
    public:
    FileSave(/*args*/) = default;
    ~FileSave() = default;

    void save_with_member_fun(const std::string &file_name)
    {
        std::cout << "调用了成员方法，保存:" << file_name << std::endl;
    };
};

int main()
{
    FileSave file_save;
    // Lambda function

    auto save_with_lambda_fun = [](const std::string &file_name) -> void
    {
        std::cout << "Lambda function: " << file_name << std::endl;
    };

    // save_with_frr_fun("file.txt");
    // file_save.save_with_member_fun("file.txt");
    // save_with_lambda_fun("file.txt");

    std::function<void(const std::string&)> save1 = save_with_free_fun;
    std::function<void(const std::string&)> save2 = save_with_lambda_fun;
    // put member function in functional
    std::function<void(const std::string&)> save3 = std::bind(&FileSave::save_with_member_fun,&file_save,std::placeholders::_1);

    // unified calling methods
    save1("file.txt");
    save2("file.txt");
    save3("file.txt");

    return 0;
}