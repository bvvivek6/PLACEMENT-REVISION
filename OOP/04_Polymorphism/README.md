# Polymorphism

## 1. What is Polymorphism?

Polymorphism means "many forms". It allows a function or an object to behave differently in different contexts.

**Interview Answer**: "Polymorphism allows us to perform a single action in different ways. In C++, it is mainly divided into Compile-time and Run-time polymorphism."

## 2. Types of Polymorphism

### A. Compile-time Polymorphism (Static Binding)

The function to be invoked is determined at compile time.

1.  **Function Overloading**: Multiple functions with the same name but different parameters (type or number).
2.  **Operator Overloading**: Giving special meaning to existing operators (like `+`, `-`) for user-defined types.

### Example: Function Overloading

```cpp
#include <iostream>

class Print {
public:
    void display(int i) { std::cout << "Integer: " << i << std::endl; }
    void display(double f) { std::cout << "Float: " << f << std::endl; }
    void display(std::string s) { std::cout << "String: " << s << std::endl; }
};

int main() {
    Print obj;
    obj.display(5);
    obj.display(500.263);
    obj.display("Hello C++");
    return 0;
}
```

### Example: Operator Overloading

```cpp
#include <iostream>

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator + (const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() { std::cout << real << " + " << imag << "i" << std::endl; }
};

int main() {
    Complex c1(3.3, 4.4), c2(1.1, 2.2);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
```

### B. Run-time Polymorphism (Dynamic Binding)

The function to be invoked is determined at run time.

1.  **Function Overriding**: A derived class provides a specific implementation for a function already defined in its base class.
2.  **Virtual Functions**: Used to achieve run-time polymorphism.

## 3. Virtual Functions

A `virtual` function is a member function in the base class that you expect to override in derived classes.

- When a pointer of a base class points to an object of the derived class, calling a virtual function executes the derived class's version.
- Without `virtual`, the base class version is called (static binding).

### Example: Virtual Functions

```cpp
#include <iostream>

class Base {
public:
    virtual void print() { std::cout << "Base Function" << std::endl; }
    void show() { std::cout << "Base Show Function" << std::endl; }
};

class Derived : public Base {
public:
    void print() override { std::cout << "Derived Function" << std::endl; }
    void show() { std::cout << "Derived Show Function" << std::endl; }
};

int main() {
    Base* bptr;
    Derived d;
    bptr = &d;

    bptr->print(); // Output: Derived Function (Virtual)
    bptr->show();  // Output: Base Show Function (Non-virtual)
    return 0;
}
```

## 4. How Virtual Functions Work (V-Table and V-Ptr)

**This is a very common interview question.**

- **V-Table (Virtual Table)**: A static table created by the compiler for every class that has virtual functions. It contains function pointers to the virtual functions of that class.
- **V-Ptr (Virtual Pointer)**: A hidden pointer added by the compiler to every object of a class with virtual functions. It points to the V-Table of that class.
