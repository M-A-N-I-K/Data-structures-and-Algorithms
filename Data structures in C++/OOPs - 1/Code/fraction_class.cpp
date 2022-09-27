#include <iostream>
#include <algorithm>
using namespace std;

class fraction
{
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    void add(fraction const &f)
    {
        int lcm = denominator * f.denominator;
        int x = lcm / denominator;
        int y = lcm / f.denominator;
        int num = x * numerator + (y * f.numerator);
        numerator = num;
        denominator = lcm;

        simplify();
    }

    void multiply(fraction const &f1)
    {
        numerator = numerator * f1.numerator;
        denominator = denominator * f1.denominator;
        simplify();
    }

    void print()
    {
        cout << numerator << " / " << denominator << endl;
    }
};

int main()
{
    fraction f1(2, 5);
    fraction f2(5, 10);
    f1.print();
    f2.print();
    f1.add(f2);
    f1.print();
    f2.print();
    f2.multiply(f1);
    f1.print();
    f2.print();
    return 0;
}