#include <iostream>

using namespace std;

class teacher
{
public:
    string name;
    int age;

    void print()
    {
        cout << "Teacher" << endl;
    }
};

class student
{
public:
    string name;
    int age;
    void print()
    {
        cout << "Student" << endl;
    }
};

class TA : public teacher, public student
{
    public:
        void print(){
            cout << "TA" << endl;
        }
};

int main()
{
    TA t;
    t.student ::print();
}