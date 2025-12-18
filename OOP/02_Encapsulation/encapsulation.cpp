#include <iostream>
#include <string>

class Employee
{
private:
    // Private data members: cannot be accessed directly from outside the class
    std::string name;
    double salary;

public:
    // Constructor
    Employee(std::string n, double s)
    {
        name = n;
        setSalary(s); // Use setter to validate
    }

    // Getter for name
    std::string getName()
    {
        return name;
    }

    // Setter for name
    void setName(std::string n)
    {
        name = n;
    }

    // Getter for salary
    double getSalary()
    {
        return salary;
    }

    // Setter for salary with validation
    void setSalary(double s)
    {
        if (s >= 0)
        {
            salary = s;
        }
        else
        {
            std::cout << "Invalid salary! Salary cannot be negative." << std::endl;
            salary = 0;
        }
    }
};

int main()
{
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
