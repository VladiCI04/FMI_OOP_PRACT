#include <iostream>


// Global Constants
namespace GlobalConstants {
    const unsigned short NAME_MAX_SIZE = 30;
};

// Structs
struct Student {
    char* name = new char[GlobalConstants::NAME_MAX_SIZE];
    unsigned short age;
    unsigned int fn;

    Student() {
        this->name = (char*)"Name";
        this->age = 0;
        this->fn = 11111111;
    }

    Student(const char* name, const unsigned short age, const unsigned int fn) {
        this->name = (char*)name;
        this->age = age;
        this->fn = fn;
    }
};

// Functions
void writeStudent(const Student& s) {
    std::cout << s.name << ' ' << s.age << ' ' << s.fn << std::endl;
}

int main()
{
    Student s1;
    Student s2("Ivan", 20, 222222);

    writeStudent(s1);
    writeStudent(s2);
}