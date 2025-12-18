#include <iostream>
#include <string>

class Person
{
private:
    std::string name;
    int age;

public:
    // 1. Default Constructor
    // Called when an object is created without arguments.
    Person()
    {
        name = "Unknown";
        age = 0;
        std::cout << "Default Constructor called" << std::endl;
    }

    // 2. Parameterized Constructor
    // Called when an object is created with arguments.
    Person(std::string n, int a)
    {
        name = n;
        age = a;
        std::cout << "Parameterized Constructor called for " << name << std::endl;
    }

    // 3. Copy Constructor
    // Called when an object is initialized with another object of the same class.
    Person(const Person &p)
    {
        name = p.name;
        age = p.age;
        std::cout << "Copy Constructor called for " << name << std::endl;
    }

    void display()
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main()
{
    // Default constructor
    Person p1;
    p1.display();

    // Parameterized constructor
    Person p2("Alice", 30);
    p2.display();

    // Copy constructor
    Person p3 = p2; // or Person p3(p2);
    p3.display();

    return 0;
}
