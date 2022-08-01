#include <iostream>
#include <climits>
using namespace std;
template <typename T>
class stack
{
    T *arr;
    int capacity;
    int nextIndex;

public:
    stack()
    {
        arr = new T[4];
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

    void push(T data)
    {
        if (isFull())
        {
            T *newArr = new T[2 * capacity];
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
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return arr[nextIndex];
    }
    T top()
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
    stack<int> s;
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