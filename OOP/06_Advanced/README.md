# Advanced C++ OOP Concepts

## 1. Friend Functions and Classes

- **Friend Function**: A function that is not a member of a class but has access to its private and protected members.
- **Friend Class**: A class where all member functions are friends of another class.
- **Use Case**: Operator overloading, or when two distinct classes need to work closely together.

### Example: Friend Function

```cpp
#include <iostream>

class Box {
private:
    double width;
public:
    Box(double w) : width(w) {}
    friend void printWidth(Box box);
};

void printWidth(Box box) {
    // Access private member
    std::cout << "Width of box: " << box.width << std::endl;
}

int main() {
    Box box(10.0);
    printWidth(box);
    return 0;
}
```

## 2. Static Members

- **Static Variable**: Shared by all objects of the class. Memory is allocated only once.
- **Static Function**: Can be called without an object (`Class::method()`). Can only access static data members.

### Example: Static Members

```cpp
#include <iostream>

class Counter {
public:
    static int count;
    Counter() { count++; }
    static int getCount() { return count; }
};

int Counter::count = 0;

int main() {
    Counter c1, c2, c3;
    std::cout << "Count: " << Counter::getCount() << std::endl; // Output: 3
    return 0;
}
```

## 3. Templates (Generics)

Templates allow writing generic programs. You can create a single function or class to work with different data types.

### Example: Templates

```cpp
#include <iostream>

// Function Template
template <typename T>
T add(T a, T b) { return a + b; }

// Class Template
template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

int main() {
    std::cout << add(10, 20) << std::endl;
    Box<std::string> strBox("Hello");
    std::cout << strBox.getValue() << std::endl;
    return 0;
}
```

## 4. Smart Pointers (RAII)

Smart pointers automatically manage memory, preventing memory leaks. They are part of the `<memory>` header.

1.  **`std::unique_ptr`**: Owns the object exclusively. Cannot be copied, only moved.
2.  **`std::shared_ptr`**: Shared ownership. Uses reference counting.
3.  **`std::weak_ptr`**: A non-owning reference to an object managed by `shared_ptr`.

### Example: Smart Pointers

```cpp
#include <iostream>
#include <memory>

class Entity {
public:
    Entity() { std::cout << "Entity Created!" << std::endl; }
    ~Entity() { std::cout << "Entity Destroyed!" << std::endl; }
    void print() { std::cout << "Entity Print" << std::endl; }
};

int main() {
    // unique_ptr
    {
        std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
        entity1->print();
    } // entity1 destroyed here

    // shared_ptr
    {
        std::shared_ptr<Entity> sharedEntity1;
        {
            std::shared_ptr<Entity> sharedEntity2 = std::make_shared<Entity>();
            sharedEntity1 = sharedEntity2; // Ref count = 2
        } // Ref count = 1
    } // Ref count = 0, destroyed
    return 0;
}
```

## 5. Move Semantics (C++11)

Move semantics allow resources (like dynamic memory) to be "moved" from one object to another instead of copying. This improves performance significantly.

- **Move Constructor**: `ClassName(ClassName&& other)`. It takes an R-value reference (`&&`) and "steals" the resources.

### Example: Move Semantics

```cpp
#include <iostream>
#include <string>
#include <utility> // for std::move

class String {
public:
    String() = default;
    String(const char* string) {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    // Move Constructor
    String(String&& other) noexcept {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    ~String() { delete[] m_Data; }
    void print() { printf("String data\n"); }
private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity {
public:
    Entity(String&& name) : m_Name(std::move(name)) {}
private:
    String m_Name;
};

int main() {
    Entity entity(String("Cherno")); // "Moved!"
    return 0;
}
```
