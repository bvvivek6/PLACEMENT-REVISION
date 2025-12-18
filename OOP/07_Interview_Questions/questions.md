# Common C++ OOP Interview Questions

## 1. What are the main pillars of OOP?

- **Encapsulation**: Bundling data and methods that operate on that data within a single unit (class) and restricting access to some of the object's components.
- **Abstraction**: Hiding complex implementation details and showing only the necessary features of an object.
- **Inheritance**: The mechanism by which one class acquires the properties and behavior of another class.
- **Polymorphism**: The ability of a message to be displayed in more than one form (e.g., function overloading, virtual functions).

## 2. What is the difference between `struct` and `class` in C++?

- In a `class`, members are **private** by default.
- In a `struct`, members are **public** by default.
- Otherwise, they are functionally equivalent (both can have methods, constructors, inheritance, etc.).

## 3. What is a Virtual Function?

A virtual function is a member function in the base class that you expect to override in derived classes. It ensures that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call. This is used to achieve **Runtime Polymorphism**.

## 4. What is a Pure Virtual Function?

A pure virtual function is a function that has no implementation in the base class and is declared by assigning 0.
Example: `virtual void draw() = 0;`
A class containing at least one pure virtual function is called an **Abstract Class** and cannot be instantiated.

## 5. What is the Diamond Problem?

The Diamond Problem occurs in multiple inheritance when two classes inherit from a common base class, and a fourth class inherits from both of them. This creates ambiguity because the fourth class has two copies of the common base class.
**Solution**: Use **Virtual Inheritance** (`class B : virtual public A`).

## 6. What is the difference between Overloading and Overriding?

- **Overloading**: Same function name, different parameters (compile-time polymorphism).
- **Overriding**: Same function name and parameters in base and derived classes (runtime polymorphism).

## 7. What is a Constructor? Types of Constructors?

A constructor is a special member function that is automatically called when an object is created.

- **Default Constructor**: No arguments.
- **Parameterized Constructor**: Takes arguments.
- **Copy Constructor**: Initializes an object using another object of the same class.
- **Move Constructor** (C++11): Initializes an object by transferring resources from a temporary object.

## 8. What is a Destructor? Can it be virtual?

A destructor is a special member function called when an object is destroyed. It releases resources.
**Yes**, a destructor should be **virtual** in a base class if you plan to delete a derived class object through a base class pointer. If not virtual, only the base class destructor will be called, leading to memory leaks.

## 9. What is the `this` pointer?

`this` is a constant pointer that holds the memory address of the current object. It is passed as a hidden argument to all non-static member functions.

## 10. What are Smart Pointers?

Smart pointers are wrappers around raw pointers that automatically manage memory (RAII).

- `std::unique_ptr`: Exclusive ownership.
- `std::shared_ptr`: Shared ownership (reference counting).
- `std::weak_ptr`: Non-owning reference to an object managed by `shared_ptr` (prevents cyclic references).

## 11. What is the difference between `new` and `malloc`?

- `new` calls the constructor, `malloc` does not.
- `new` returns the exact data type, `malloc` returns `void*`.
- `new` throws an exception on failure, `malloc` returns `NULL`.
- `delete` calls the destructor, `free` does not.

## 12. What is a Friend Function?

A friend function is a function that is not a member of a class but has access to its private and protected members. It is declared using the `friend` keyword.
