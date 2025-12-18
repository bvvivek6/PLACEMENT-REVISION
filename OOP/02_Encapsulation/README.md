# Encapsulation

## 1. What is Encapsulation?

Encapsulation is the bundling of data (variables) and methods (functions) that operate on the data into a single unit (class). It also involves restricting direct access to some of an object's components.

**Interview Answer**: "Encapsulation is about wrapping data and methods together and hiding the internal details of how the data is processed. It is often achieved using access modifiers."

## 2. Data Hiding

Data hiding is the mechanism of hiding internal object details (data members) from the outside world. This ensures that the object's state remains consistent and is not corrupted by external interference.

## 3. Access Modifiers

C++ provides three access specifiers to control access to class members:

| Modifier      | Access Inside Class | Access in Derived Class | Access Outside Class |
| :------------ | :-----------------: | :---------------------: | :------------------: |
| **private**   |         Yes         |           No            |          No          |
| **protected** |         Yes         |           Yes           |          No          |
| **public**    |         Yes         |           Yes           |         Yes          |

- **private**: Accessible only within the class. Default for `class`.
- **protected**: Accessible within the class and its derived classes.
- **public**: Accessible from anywhere. Default for `struct`.

## 4. Getters and Setters

Since private data cannot be accessed directly, public methods (Getters and Setters) are provided to access and modify them.

- **Getter**: Returns the value of a private member.
- **Setter**: Sets the value of a private member, often including validation logic to ensure data integrity.

### Example: Encapsulation with Getters and Setters

```cpp
#include <iostream>
#include <string>

class Employee {
private:
    // Private data members: cannot be accessed directly from outside the class
    std::string name;
    double salary;

public:
    // Constructor
    Employee(std::string n, double s) {
        name = n;
        setSalary(s); // Use setter to validate
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Setter for name
    void setName(std::string n) {
        name = n;
    }

    // Getter for salary
    double getSalary() {
        return salary;
    }

    // Setter for salary with validation
    void setSalary(double s) {
        if (s >= 0) {
            salary = s;
        } else {
            std::cout << "Invalid salary! Salary cannot be negative." << std::endl;
            salary = 0;
        }
    }
};

int main() {
    Employee emp("John Doe", 50000);

    // emp.salary = 60000; // Error: salary is private

    std::cout << "Name: " << emp.getName() << std::endl;
    std::cout << "Salary: " << emp.getSalary() << std::endl;

    // Update salary
    emp.setSalary(55000);
    std::cout << "Updated Salary: " << emp.getSalary() << std::endl;

    // Try setting invalid salary
    emp.setSalary(-1000);
    std::cout << "Salary after invalid update: " << emp.getSalary() << std::endl;

    return 0;
}
```
