#include <iostream>

using namespace std;

class vehicle
{
public:
    string color;
    virtual void print()
    {
        cout << "vehicle" << endl;
    }
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
    vehicle v;
    car c;
    v.print();
    c.print();

    vehicle *v1 = new vehicle;
    vehicle *v2;
    // v2 = &v;
    v2 = &c;
    v2->print();
    v1->print();
}