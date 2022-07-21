#include <iostream>
using namespace std;

class Polynomial
{

public:
    // Complete the class
    int *degCoeff; // Name of your array (Don't change this)
    int nextIndex;
    int capacity;

    Polynomial()
    {
        degCoeff = new int(5);
        nextIndex = 0;
        capacity = 5;
    }

    Polynomial(Polynomial const &p)
    {
        degCoeff = new int[p.capacity];
        for (int i = 0; i < p.nextIndex; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        nextIndex = p.nextIndex;
        capacity = p.capacity;
    }

    void setCoefficient(int degree, int coeff)
    {
        if (degree > capacity)
        {
            int *newDegCoeff = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            capacity = 2 * capacity;
        }
        degCoeff[nextIndex] = coeff;
        nextIndex++;
    }

    Polynomial operator+(Polynomial const &p)
    {
        Polynomial New;
        for (int i = 0; i < nextIndex; i++)
        {
            New.degCoeff[i] = degCoeff[i] + p.degCoeff[i];
        }
        return New;
    }

    Polynomial operator-(Polynomial const &p)
    {
        Polynomial New;
        for (int i = 0; i < nextIndex; i++)
        {
            New.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
        }
        return New;
    }
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial New;
        for (int i = 0; i < nextIndex; i++)
        {
            New.degCoeff[i] = degCoeff[i] * p.degCoeff[i];
        }
        return New;
    }

    void operator=(Polynomial const &p)
    {
        degCoeff = new int[p.capacity];
        for (int i = 0; i < p.nextIndex; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        nextIndex = p.nextIndex;
        capacity = p.capacity;
    }

    bool operator==(Polynomial const &p)
    {
        for (int i = 0; i < nextIndex; i++)
        {
            if (degCoeff[i] != p.degCoeff[i])
            {
                return false;
            }
        }
        return true;
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    case 3:
    {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }
    return 0;
}