#include <iostream>
#include <climits>
using namespace std;

class stack
{
    int *arr;
    int capacity;
    int nextIndex;

public:
    stack(int totalSize)
    {
        arr = new int[totalSize];
        capacity = totalSize;
        nextIndex = 0;
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
            cout << "Stack Overflow" << endl;
            return;
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
    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.pop() << endl;
    // cout << s.isEmpty() << endl;
    // cout << s.isFull() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
    return 0;
}