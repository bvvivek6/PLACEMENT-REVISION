#include <iostream>

class Resource
{
private:
    int *data;

public:
    Resource()
    {
        data = new int[10]; // Allocate memory
        std::cout << "Resource acquired (Constructor)" << std::endl;
    }

    ~Resource()
    {
        delete[] data; // Release memory
        std::cout << "Resource released (Destructor)" << std::endl;
    }
};

int main()
{
    {
        Resource res; // Constructor called
        // Do something with res
    } // Destructor called automatically when res goes out of scope

    std::cout << "End of main" << std::endl;
    return 0;
}
