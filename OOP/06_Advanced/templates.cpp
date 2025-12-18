#include <iostream>

// Function Template
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// Class Template
template <typename T>
class Box
{
private:
    T value;

public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

int main()
{
    // Function Template usage
    std::cout << "Add int: " << add(10, 20) << std::endl;
    std::cout << "Add double: " << add(10.5, 20.5) << std::endl;

    // Class Template usage
    Box<int> intBox(100);
    Box<std::string> strBox("Hello");

    std::cout << "Int Box: " << intBox.getValue() << std::endl;
    std::cout << "String Box: " << strBox.getValue() << std::endl;

    return 0;
}
