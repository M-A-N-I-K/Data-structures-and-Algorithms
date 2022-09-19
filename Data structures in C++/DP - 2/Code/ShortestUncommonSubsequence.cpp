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
#include <algorithm>
#define MAX 1056

using namespace std;

int solveDP(string s, string t)
{
    int **dp = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        dp[i] = new int[t.length() + 1];
    }
    for (int i = 0; i <= s.length(); i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= t.length(); i++)
    {
        dp[0][i] = MAX;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            char ch = s[i - 1];
            int k;
            for (k = j - 1; k >= 0; k--)
            {
                if (t[k] == ch)
                {
                    break;
                }
            }
            if (k == -1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][k] + 1);
            }
        }
    }
    int ans = dp[s.length()][t.length()];
    if (ans > MAX)
    {
        ans = -1;
    }
    for (int i = 0; i <= s.length(); i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

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