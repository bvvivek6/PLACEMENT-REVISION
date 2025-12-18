#include <iostream>

class Counter
{
public:
    static int count; // Static data member declaration

    Counter()
    {
        count++;
    }

    static int getCount()
    { // Static member function
        return count;
    }
};

// Initialize static member
int Counter::count = 0;

int main()
{
    std::cout << "Initial Count: " << Counter::getCount() << std::endl;

    Counter c1;
    Counter c2;
    Counter c3;

    std::cout << "Count after creating 3 objects: " << Counter::getCount() << std::endl;

    return 0;
}
