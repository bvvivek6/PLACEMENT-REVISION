#include <iostream>

class Base
{
public:
    // Virtual function
    virtual void print()
    {
        std::cout << "Base Function" << std::endl;
    }

    void show()
    {
        std::cout << "Base Show Function" << std::endl;
    }
};

class Derived : public Base
{
public:
    // Override base function
    void print() override
    {
        std::cout << "Derived Function" << std::endl;
    }

    void show()
    {
        std::cout << "Derived Show Function" << std::endl;
    }
};

int main()
{
    Base *bptr;
    Derived d;
    bptr = &d;

    // Virtual function, binded at runtime
    bptr->print(); // Output: Derived Function

    // Non-virtual function, binded at compile time
    bptr->show(); // Output: Base Show Function

    return 0;
}
