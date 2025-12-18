#include <iostream>

// Base class 1
class Mammal
{
public:
    Mammal()
    {
        std::cout << "Mammal constructor" << std::endl;
    }
    void breathe()
    {
        std::cout << "I can breathe." << std::endl;
    }
};

// Base class 2
class WingedAnimal
{
public:
    WingedAnimal()
    {
        std::cout << "WingedAnimal constructor" << std::endl;
    }
    void fly()
    {
        std::cout << "I can fly." << std::endl;
    }
};

// Derived class inheriting from both Mammal and WingedAnimal
class Bat : public Mammal, public WingedAnimal
{
public:
    Bat()
    {
        std::cout << "Bat constructor" << std::endl;
    }
};

int main()
{
    Bat b1;
    b1.breathe();
    b1.fly();

    return 0;
}
