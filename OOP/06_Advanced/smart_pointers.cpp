#include <iostream>
#include <memory> // Required for smart pointers

class Entity
{
public:
    Entity() { std::cout << "Entity Created!" << std::endl; }
    ~Entity() { std::cout << "Entity Destroyed!" << std::endl; }
    void print() { std::cout << "Entity Print" << std::endl; }
};

int main()
{
    // 1. unique_ptr
    // Scoped pointer. Cannot be copied, only moved.
    {
        std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
        entity1->print();
    } // entity1 is destroyed here automatically

    // 2. shared_ptr
    // Reference counting. Deleted when reference count reaches 0.
    {
        std::shared_ptr<Entity> sharedEntity1;
        {
            std::shared_ptr<Entity> sharedEntity2 = std::make_shared<Entity>();
            sharedEntity1 = sharedEntity2; // Reference count = 2
            std::cout << "Inside inner scope" << std::endl;
        } // sharedEntity2 goes out of scope, Reference count = 1
        std::cout << "Outside inner scope" << std::endl;
    } // sharedEntity1 goes out of scope, Reference count = 0, Entity destroyed

    return 0;
}
