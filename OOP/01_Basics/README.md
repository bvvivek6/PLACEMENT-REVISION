# Basics of Object-Oriented Programming

## 1. What is Object-Oriented Programming (OOP)?

OOP is a programming paradigm based on the concept of "objects", which can contain data (attributes) and code (methods). It aims to implement real-world entities like inheritance, hiding, polymorphism, etc., in programming.

## 2. Class vs. Object

- **Class**: A user-defined data type that acts as a blueprint for creating objects. It defines the properties and behaviors. It does not occupy memory until an object is instantiated.
- **Object**: An instance of a class. It is a real-world entity that occupies memory.

**Interview Answer**: "A class is a logical template, while an object is a physical instance of that template."

### Example: Class and Object

```cpp
#include <iostream>
#include <string>

// A Class is a blueprint for creating objects.
class Car {
public:
    // Data members (Attributes)
    std::string brand;
    std::string model;
    int year;

    // Member function (Method)
    void displayInfo() {
        std::cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << std::endl;
    }
};

int main() {
    // Create an object of Car
    Car myCar;

    // Access attributes and set values
    myCar.brand = "Toyota";
    myCar.model = "Corolla";
    myCar.year = 2020;

    // Call member function
    myCar.displayInfo();

    return 0;
}
```

## 3. Constructors

A constructor is a special member function initialized automatically when an object is created.

- **Name**: Same as the class name.
- **Return Type**: None (not even void).
- **Types**:
  1.  **Default Constructor**: Takes no arguments.
  2.  **Parameterized Constructor**: Takes arguments to initialize the object with specific values.
  3.  **Copy Constructor**: Creates a new object as a copy of an existing object. `ClassName(const ClassName &obj)`.

### Example: Constructors

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // 1. Default Constructor
    Person() {
        name = "Unknown";
        age = 0;
        std::cout << "Default Constructor called" << std::endl;
    }

    // 2. Parameterized Constructor
    Person(std::string n, int a) {
        name = n;
        age = a;
        std::cout << "Parameterized Constructor called for " << name << std::endl;
    }

    // 3. Copy Constructor
    Person(const Person &p) {
        name = p.name;
        age = p.age;
        std::cout << "Copy Constructor called for " << name << std::endl;
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person p1;                  // Default
    Person p2("Alice", 30);     // Parameterized
    Person p3 = p2;             // Copy
    return 0;
}
```

## 4. Destructors

A destructor is a special member function called automatically when an object goes out of scope or is explicitly deleted.

- **Name**: Same as class name preceded by `~`.
- **Purpose**: To release resources (memory, file handles) allocated to the object.
- **Note**: There can be only one destructor per class.

### Example: Destructors

```cpp
#include <iostream>

class Resource {
private:
    int* data;

public:
    Resource() {
        data = new int[10]; // Allocate memory
        std::cout << "Resource acquired (Constructor)" << std::endl;
    }

    ~Resource() {
        delete[] data; // Release memory
        std::cout << "Resource released (Destructor)" << std::endl;
    }
};

int main() {
    {
        Resource res; // Constructor called
    } // Destructor called automatically when res goes out of scope
    return 0;
}
```

## 5. The `this` Pointer

`this` is a constant pointer that holds the memory address of the current object. It is passed as a hidden argument to all non-static member functions.

- **Usage**: To distinguish between local variables and member variables when names collide.
