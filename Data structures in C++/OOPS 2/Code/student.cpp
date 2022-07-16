#include <iostream>
#include <string.h>
using namespace std;

class student
{
    int age;
    char *name;

public:
    student(int age, char *name)
    {
        this->age = age;

        // Shallow Copy :
        // this->name = name;

        // Deep Copy :
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
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
    name[3] = 'e';
    student s2(20, name);
    s1.display();
    s2.display();
    s1.display();
    return 0;
}