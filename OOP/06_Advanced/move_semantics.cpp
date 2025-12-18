#include <iostream>
#include <vector>
#include <string>

class String
{
public:
    String() = default;
    String(const char *string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    // Copy Constructor
    String(const String &other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    // Move Constructor
    String(String &&other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data; // Steal the data

        // Reset the source object
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    ~String()
    {
        printf("Destroyed!\n");
        delete[] m_Data;
    }

    void print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
            printf("%c", m_Data[i]);
        printf("\n");
    }

private:
    char *m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    Entity(const String &name) : m_Name(name) {}

    // Move Constructor for Entity
    Entity(String &&name) : m_Name(std::move(name)) {}

    void printName()
    {
        m_Name.print();
    }

private:
    String m_Name;
};

int main()
{
    // Without move semantics (Copy)
    // Entity entity("Cherno");

    // With move semantics
    Entity entity(String("Cherno")); // "Moved!" should be printed
    entity.printName();

    return 0;
}
