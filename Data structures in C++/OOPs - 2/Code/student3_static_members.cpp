#include <iostream>
using namespace std;

class student
{
public:
    int rollNumber;
    int age;
    static int totalStudents; // Total number of students

    student()
    {
        totalStudents++;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }
};

int student ::totalStudents = 0; // Initializing static data members

int main()
{
    student s1;
    cout << s1.rollNumber << " " << s1.age << endl;
    cout << student ::totalStudents << endl;
    return 0;
}