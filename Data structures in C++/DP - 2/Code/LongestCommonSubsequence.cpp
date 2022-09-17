#include <iostream>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string s, string t)
{
    // Base Case
    if (s.empty() || t.empty())
    {
        return 0;
    }
    // Recursive calls
    if (s[0] == t[0])
    {
        return 1 + longestCommonSubsequence(s.substr(1), t.substr(1));
    }
    else
    {
        int a = longestCommonSubsequence(s.substr(1), t);
        int b = longestCommonSubsequence(s, t.substr(1));
        int c = longestCommonSubsequence(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << longestCommonSubsequence(s, t) << endl;
}