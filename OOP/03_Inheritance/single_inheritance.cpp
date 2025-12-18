#include <iostream>

// Base class
class Animal
{
public:
    void eat()
    {
        std::cout << "I can eat!" << std::endl;
    }

    void sleep()
    {
        std::cout << "I can sleep!" << std::endl;
    }
};

// Derived class
class Dog : public Animal
{
public:
    void bark()
    {
        std::cout << "I can bark! Woof woof!" << std::endl;
    }
};

int main()
{
    Dog dog1;

    // Calling members of the base class
    dog1.eat();
    dog1.sleep();

    // Calling member of the derived class
    dog1.bark();

    return 0;
}
