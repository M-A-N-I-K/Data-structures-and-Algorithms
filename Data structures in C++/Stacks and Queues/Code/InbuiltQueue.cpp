#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << q.size() << endl;
    ;
    cout << q.front() << endl;
    cout << q.empty() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.size() << endl;
    return 0;
}