#include <iostream>

// Abstract class
class Shape
{
public:
    // Pure virtual function
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};

int main()
{
    // Shape s; // Error: Cannot instantiate abstract class

    Circle c;
    Rectangle r;

    Shape *s1 = &c;
    Shape *s2 = &r;

    s1->draw();
    s2->draw();

    return 0;
}
