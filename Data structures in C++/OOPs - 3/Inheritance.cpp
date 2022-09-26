#include <iostream>

using namespace std;

class vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;
    vehicle()
    {
        cout << "This is constructor of vehicle class" << endl;
    }
    vehicle(int z)
    {
        cout << "This is Parameterized constructor of vehicle class" << endl;
        maxSpeed = z;
    }
    ~vehicle()
    {
        cout << "This is destructor of vehicle class" << endl;
    }
};

class car : public vehicle
{
public:
    int numGears;
    car(int x, int y) : vehicle(x)
    {
        cout << "This is constructor of car class" << endl;
        numGears = y;
    }
    ~car()
    {
        cout << "This is destructor of car class" << endl;
    }
    void print()
    {
        cout << "Numtyres  : " << numTyres << endl;
        cout << "Color  : " << color << endl;
        cout << "NumGears  : " << numGears << endl;
    }
};

class hondaCity : public car
{
public:
    hondaCity(int x, int y) : car(x, y)
    {
        cout << "Honda city constructor" << endl;
    }
    ~hondaCity()
    {
        cout << "Honda city destructor" << endl;
    }
};

int main()
{
    // vehicle v;
    // v.color = "Blue";
    // v.maxSpeed = 100;
    // v.numTyres = 4;

    // car c(10);
    // c.color = "Red";
    // c.numGears = 6;
    // c.print();

    hondaCity h(10, 20);
}