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
    // Dont use [] this for inserting elements
    // cout << vec[3] << endl;

    cout << "Size : " << vec.size() << endl;

    // Much safer to use to access elements
    cout << vec.at(2) << endl;
    // cout << vec.at(4) << endl;
    vec.pop_back();
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}