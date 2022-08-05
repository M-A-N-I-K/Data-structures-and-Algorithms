#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> *v = new vector<int>();
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    cout << vec[0] << endl;
    cout << vec[1] << endl;
    cout << vec[2] << endl;
    return 0;
}