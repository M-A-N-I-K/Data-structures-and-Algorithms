#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> ourMap;

    //  Insertion :
    pair<string, int> p("abc", 1);
    ourMap.insert(p);

    // Find or access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;

    cout << "Size : " << ourMap.size() << endl;
    cout << ourMap["ghi"] << endl;
    // cout << ourMap.at("ghi") << endl;
    cout << "Size : " << ourMap.size() << endl;

    // Check presence
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
}