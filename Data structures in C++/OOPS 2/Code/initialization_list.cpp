#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    const int rollNumber;
    int &x; // Age reference variable

    Student(int r, int a) : rollNumber(r), age(a), x(this->age)
    {
        // rollNumber = r (Not allowed in case of const)
    }
};

int main()
{
    Student s(101, 20);

    return 0;
}