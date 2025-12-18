#include <iostream>

// The Diamond Problem occurs when two superclasses of a class have a common base class.
// Without virtual inheritance, the derived class would have two copies of the base class.

class Person
{
public:
    Person() { std::cout << "Person constructor called" << std::endl; }
    void walk() { std::cout << "Person walking" << std::endl; }
};

// Virtual inheritance solves the diamond problem
class Student : virtual public Person
{
public:
    Student() { std::cout << "Student constructor called" << std::endl; }
};

class Faculty : virtual public Person
{
public:
    Faculty() { std::cout << "Faculty constructor called" << std::endl; }
};

class TA : public Student, public Faculty
{
public:
    TA() { std::cout << "TA constructor called" << std::endl; }
};

int main()
{
    TA ta1;
    ta1.walk(); // Without virtual inheritance, this would be ambiguous

    return 0;
}
