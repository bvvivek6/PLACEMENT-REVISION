#include <iostream>
#include <string>

// A Class is a blueprint for creating objects.
class Car
{
public:
    // Data members (Attributes)
    std::string brand;
    std::string model;
    int year;

    // Member function (Method)
    void displayInfo()
    {
        std::cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << std::endl;
    }
};

int main()
{
    // Create an object of Car
    Car myCar;

    // Access attributes and set values
    myCar.brand = "Toyota";
    myCar.model = "Corolla";
    myCar.year = 2020;

    // Call member function
    myCar.displayInfo();

    // Create another object
    Car anotherCar;
    anotherCar.brand = "Honda";
    anotherCar.model = "Civic";
    anotherCar.year = 2022;

    anotherCar.displayInfo();

    return 0;
}
