#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicate(int *arr, int n)
{
    vector<int> output;
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(arr[i]) > 0)
        {
            mp[arr[i]] == true;
            continue;
        }
        mp[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 3, 2, 4, 5, 6, 4};
    vector<int> ans = removeDuplicate(arr, 10);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}