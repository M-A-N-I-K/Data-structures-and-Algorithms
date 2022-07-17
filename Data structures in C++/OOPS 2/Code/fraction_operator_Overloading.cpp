#include <iostream>
using namespace std;

class fraction
{
    int numerator;
    int denominator;

public:
    fraction()
    {
    }

    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    void setNumerator(int n)
    {
        numerator = n;
    }

    void setDenominator(int d)
    {
        denominator = d;
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

    fraction operator+(fraction const &f)
    {
        int lcm = denominator * f.denominator;
        int x = lcm / denominator;
        int y = lcm / f.denominator;
        int num = x * numerator + (y * f.numerator);
        fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }

    fraction operator*(fraction const &f1)
    {
        int n = numerator * f1.numerator;
        int d = denominator * f1.denominator;
        fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }
    bool operator==(fraction const &f1)
    {
        if (numerator == f1.numerator && denominator == f1.denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print() const
    {
        cout << numerator << " / " << denominator << endl;
    }
};
int main()
{
    fraction f1(10, 2);
    fraction f2(15, 4);

    fraction f3 = f1 * f2;
    fraction f4 = f1 + f2;
    f3.print();
    f4.print();

    if (f3 == f4)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    return 0;
}