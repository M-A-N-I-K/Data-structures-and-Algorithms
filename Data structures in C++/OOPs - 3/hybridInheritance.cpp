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
    // vehicle()
    // {
    //     cout << "This is constructor of vehicle class" << endl;
    // }
    void print()
    {
        cout << "Vehicle" << endl;
    }
    vehicle(int z)
    {
        cout << "This is Parameterized constructor of vehicle class : " << z << endl;
        maxSpeed = z;
    }
    ~vehicle()
    {
        cout << "This is destructor of vehicle class" << endl;
    }
};

class car : virtual public vehicle
{
public:
    int numGears;
    car() : vehicle(4)
    {
        cout << "This is the constructor of car class" << endl;
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

class truck : virtual public vehicle
{
public:
    truck() : vehicle(3)
    {
        cout << "Truck's Constructor Called" << endl;
    }
};

class bus : public truck, public car
{
public:
    bus() : vehicle(5)
    {
        cout << "Bus's Constructor Called" << endl;
    }

    void print()
    {
        cout << "Bus" << endl;
    }
};

int main()
{
    bus b;
    b.car ::print();
}