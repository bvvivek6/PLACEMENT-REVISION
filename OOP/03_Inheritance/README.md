# Inheritance

## 1. What is Inheritance?

Inheritance is a mechanism where a new class (Derived/Child class) acquires the properties and behaviors (members) of an existing class (Base/Parent class). It promotes code reusability.

**Interview Answer**: "Inheritance allows us to create a new class from an existing class, inheriting its features while adding new ones. It represents an 'IS-A' relationship (e.g., a Dog IS-A Animal)."

## 2. Types of Inheritance

1.  **Single Inheritance**: A derived class inherits from a single base class.
2.  **Multiple Inheritance**: A derived class inherits from more than one base class.
3.  **Multilevel Inheritance**: A derived class inherits from a base class, which itself is derived from another base class (A -> B -> C).
4.  **Hierarchical Inheritance**: Multiple derived classes inherit from a single base class.
5.  **Hybrid Inheritance**: A combination of more than one type of inheritance.

### Example: Single Inheritance

```cpp
#include <iostream>

// Base class
class Animal {
public:
    void eat() { std::cout << "I can eat!" << std::endl; }
    void sleep() { std::cout << "I can sleep!" << std::endl; }
};

// Derived class
class Dog : public Animal {
public:
    void bark() { std::cout << "I can bark! Woof woof!" << std::endl; }
};

int main() {
    Dog dog1;
    dog1.eat();
    dog1.sleep();
    dog1.bark();
    return 0;
}
```

### Example: Multiple Inheritance

```cpp
#include <iostream>

class Mammal {
public:
    void breathe() { std::cout << "I can breathe." << std::endl; }
};

class WingedAnimal {
public:
    void fly() { std::cout << "I can fly." << std::endl; }
};

// Derived class inheriting from both
class Bat : public Mammal, public WingedAnimal {};

int main() {
    Bat b1;
    b1.breathe();
    b1.fly();
    return 0;
}
```

## 3. The Diamond Problem

Occurs in Multiple Inheritance when a class inherits from two classes that both inherit from a common base class. This results in two copies of the common base class members in the final derived class, causing ambiguity.

**Solution**: **Virtual Inheritance**.
Using `virtual` keyword ensures that only one instance of the base class is inherited.

### Example: Diamond Problem and Solution

```cpp
#include <iostream>

class Person {
public:
    Person() { std::cout << "Person constructor called" << std::endl; }
    void walk() { std::cout << "Person walking" << std::endl; }
};

// Virtual inheritance solves the diamond problem
class Student : virtual public Person {
public:
    Student() { std::cout << "Student constructor called" << std::endl; }
};

class Faculty : virtual public Person {
public:
    Faculty() { std::cout << "Faculty constructor called" << std::endl; }
};

class TA : public Student, public Faculty {
public:
    TA() { std::cout << "TA constructor called" << std::endl; }
};

int main() {
    TA ta1;
    ta1.walk(); // Without virtual inheritance, this would be ambiguous
    return 0;
}
```
