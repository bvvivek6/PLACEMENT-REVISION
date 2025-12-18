#include <iostream>

class Complex
{
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overload + operator to add two Complex objects
    Complex operator+(const Complex &obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display()
    {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main()
{
    Complex c1(3.3, 4.4), c2(1.1, 2.2);
    Complex c3 = c1 + c2; // Calls operator+

    std::cout << "c1 = ";
    c1.display();
    std::cout << "c2 = ";
    c2.display();
    std::cout << "c3 = ";
    c3.display();

    return 0;
}
