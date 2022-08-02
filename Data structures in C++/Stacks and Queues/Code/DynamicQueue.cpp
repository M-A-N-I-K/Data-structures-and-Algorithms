#include <iostream>
using namespace std;
template <typename T>

class queue
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int totalSize;

public:
    queue(int s)
    {
        data = new T[size];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        totalSize = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == totalSize)
        {
            T *newData = new T[2 * totalSize];
            int j = 0;
            for (int i = firstIndex; i < totalSize; i++)
            {
                newData[j++] = data[i];
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j++] = data[i];
            }
            nextIndex = totalSize;
            firstIndex = 0;
            totalSize *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % totalSize;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % totalSize;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main()
{
    queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}