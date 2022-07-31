#include <iostream>
#include <climits>
using namespace std;

class stack
{
    int *arr;
    int capacity;
    int nextIndex;

public:
    stack()
    {
        arr = new int[4];
        nextIndex = 0;
        capacity = 4;
    }
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    bool isFull()
    {
        return capacity == nextIndex;
    }

    void push(int data)
    {
        if (isFull())
        {
            int *newArr = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            capacity *= 2;
            delete[] arr;
            arr = newArr;
        }
        arr[nextIndex] = data;
        nextIndex++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return arr[nextIndex];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        return arr[nextIndex - 1];
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    // cout << s.isEmpty() << endl;
    // cout << s.isFull() << endl;
    cout << s.size() << endl;
    return 0;
}