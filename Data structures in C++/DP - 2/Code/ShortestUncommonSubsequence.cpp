/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :

The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.

Output Format :

Length of shortest subsequence in S such that it is not a subsequence in V

Constraints:

1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000
Time Limit: 1 second

Sample Input 1:

babab
babba

Sample Output 1:

3

Explanation:

"aab" is the shortest subsequence which is present in S and absent in V.
*/
#include <iostream>
#include <string>
using namespace std;

int solve(string s, string t)
{
    if (s.length() <= 0)
    {
        return 1005;
    }
    if (t.length() == 0)
    {
        return 1;
    }
    int index;
    for (index = 0; index < t.length(); index++)
    {
        if (s[0] == t[index])
        {
            break;
        }
    }
    if (index == t.length())
    {
        return 1;
    }
    int ans1 = solve(s.substr(1), t);
    int ans2 = solve(s.substr(1), t.substr(index + 1)) + 1;
    int ans = min(ans1, ans2);
    return ans;
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}