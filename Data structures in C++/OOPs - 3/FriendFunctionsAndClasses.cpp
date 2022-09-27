#include <iostream>

using namespace std;

class bus
{
public:
    void print();
};

void test();

class truck
{
private:
    int x;

protected:
    int y;

public:
    int z;
    friend class bus;
    // friend void bus ::print();
    friend void test();
};

void bus ::print()
{
    truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void test()
{
    truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

int main()
{
    bus b;
    b.print();
    test();
}