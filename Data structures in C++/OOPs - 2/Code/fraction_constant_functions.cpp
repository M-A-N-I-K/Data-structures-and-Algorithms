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

    void print() const
    {
        cout << numerator << " / " << denominator << endl;
    }
};
int main()
{
    fraction f1(10, 2);
    fraction f2(15, 4);

    fraction const f3;
    // We can call only constant functions
    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
    return 0;
}