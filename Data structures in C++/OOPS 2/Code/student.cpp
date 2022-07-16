#include <iostream>
#include <string.h>
using namespace std;

class student
{
    int age;

public:
    char *name;
    student(int age, char *name)
    {
        this->age = age;

        // Shallow Copy :
        // this->name = name;

        // Deep Copy :
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    student(student const &s)
    {
        this->age = s.age;
        // this -> name = s.name;  // Shallow copy

        // Deep Copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    char name[] = "abcd";
    student s1(24, name);
    s1.display();

    student s2(s1);
    s2.name[0] = 'x';
    s2.display();
    s1.display();
    /*
    name[3] = 'e';
    student s2(20, name);
    s1.display();
    s2.display();
    s1.display();
    */
    return 0;
}