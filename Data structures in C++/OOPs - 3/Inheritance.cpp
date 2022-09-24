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
};

class car : public vehicle
{
public:
    int numGears;

    void print()
    {
        cout << "Numtyres  : " << numTyres << endl;
        cout << "Color  : " << color << endl;
        cout << "NumGears  : " << numGears << endl;
    }
};

int main()
{
    vehicle v;
    v.color = "Blue";
    // v.maxSpeed = 100;
    // v.numTyres = 4;

    car c;
    c.color = "Red";
    c.numGears = 6;
    c.print();
}