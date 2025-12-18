#include <iostream>

class Box
{
private:
    double width;

public:
    Box(double w) : width(w) {}

    // Friend function declaration
    friend void printWidth(Box box);
};

// Friend function definition
// Note: It is not a member function of any class
void printWidth(Box box)
{
    // Because printWidth is a friend of Box, it can access private members
    std::cout << "Width of box: " << box.width << std::endl;
}

int main()
{
    Box box(10.0);
    printWidth(box);
    return 0;
}
