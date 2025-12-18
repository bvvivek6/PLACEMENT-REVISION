# Abstraction

## 1. What is Abstraction?

Abstraction is the process of hiding complex implementation details and showing only the essential features of the object. It reduces complexity and increases efficiency.

**Interview Answer**: "Abstraction is about 'what' an object does, rather than 'how' it does it. For example, when you drive a car, you know that pressing the accelerator increases speed (abstraction), but you don't need to know the internal engine mechanics (implementation)."

## 2. Abstract Classes

An abstract class is a class that cannot be instantiated. It is designed to be a base class for other classes.

- It must contain at least one **Pure Virtual Function**.
- It can have normal member functions and variables.

## 3. Pure Virtual Functions

A pure virtual function is a function that has no implementation in the base class.

- **Syntax**: `virtual void functionName() = 0;`
- Derived classes **must** override all pure virtual functions of the base class to be instantiated. If they don't, they also become abstract classes.

## 4. Interfaces in C++

C++ does not have a specific `interface` keyword like Java or C#.

- An **Interface** in C++ is implemented using an abstract class where **all** member functions are pure virtual and there are no data members.
- It defines a contract that derived classes must fulfill.

### Example: Abstract Class and Pure Virtual Function

```cpp
#include <iostream>

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};

int main() {
    // Shape s; // Error: Cannot instantiate abstract class

    Circle c;
    Rectangle r;

    Shape* s1 = &c;
    Shape* s2 = &r;

    s1->draw();
    s2->draw();

    return 0;
}
```
