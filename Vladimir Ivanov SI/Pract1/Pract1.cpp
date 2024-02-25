#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Person
{
    bool isStudent;
    short averageGrade;
    int age;
};

void createPerson(Person& p)
{
    cin >> p.isStudent >> p.age >> p.averageGrade;
}

void printStudent(const Person& p)
{
    cout << p.isStudent << ' ' << p.age << ' ' << p.averageGrade << ' ';
}

int main()
{
    Person p;

    createPerson(p);
    printStudent(p);

    Person personRef = p;
    cout << personRef.age << endl;
}