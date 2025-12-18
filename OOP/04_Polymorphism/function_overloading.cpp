#include <iostream>

class Print
{
public:
    // Function with 1 int parameter
    void display(int i)
    {
        std::cout << "Integer: " << i << std::endl;
    }

    // Function with 1 double parameter
    void display(double f)
    {
        std::cout << "Float: " << f << std::endl;
    }

    // Function with 1 string parameter
    void display(std::string s)
    {
        std::cout << "String: " << s << std::endl;
    }
};

int main()
{
    Print obj;
    obj.display(5);
    obj.display(500.263);
    obj.display("Hello C++");

    return 0;
}
