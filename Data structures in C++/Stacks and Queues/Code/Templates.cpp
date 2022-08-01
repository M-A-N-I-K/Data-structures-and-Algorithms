#include <iostream>
using namespace std;
template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setX(T data)
    {
        x = data;
    }
    void setY(V data)
    {
        y = data;
    }
    T getX()
    {
        return x;
    }
    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<Pair<int, int>, int> triplet;
    triplet.setY(30);
    Pair<int, int> temp;
    temp.setX(10);
    temp.setY(20);
    triplet.setX(temp);
    cout << triplet.getX().getX() << " " << triplet.getX().getY() << " " << triplet.getY() << endl;
    /*
    Pair<int, double> p;
    p.setX(100);
    p.setY(100.001);
    cout << p.getX() << " " << p.getY() << endl;
    */
    /*
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(10.1);
    p2.setY(20.2);
    cout << p2.getX() << " " << p2.getY() << endl;
    */
    return 0;
}