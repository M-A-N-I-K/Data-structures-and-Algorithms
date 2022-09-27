#include <iostream>

using namespace std;

class vehicle
{
public:
    string color;
    // Pure virtual Function
    virtual void print() = 0;
};

class car : public vehicle
{
public:
    int numTyres;
    void print()
    {
        cout << "car" << endl;
    }
};

int main()
{
    car c;
    c.print();

    vehicle *v2;
    // v2 = &v;
    v2 = &c;
    v2->print();
}