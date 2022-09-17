#include <iostream>
#include <algorithm>
using namespace std;

// DP Approach
int longestCommonSubsequenceDP(string s, string t)
{
    int **output = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        output[i] = new int[t.length() + 1];
    }
    for (int i = 0; i <= s.length(); i++)
    {
        output[i][0] = 0;
    }
    for (int j = 0; j <= t.length(); j++)
    {
        output[0][j] = 0;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[s.length() - i] == t[t.length() - j])
            {
                output[i][j] = output[i - 1][j - 1] + 1;
            }
            else
            {
                output[i][j] = max(output[i - 1][j], max(output[i][j - 1], output[i - 1][j - 1]));
            }
        }
    }
    return output[s.length()][t.length()];
}
// Memoization Approach
int longestCommonSubsequenceMemoization(string s, string t, int i, int j, int **output)
{
    // Base Case
    if (s.empty() || t.empty())
    {
        return 0;
    }
    // Check if answer already exists
    if (output[i][j] != -1)
    {
        return output[i][j];
    }
    // Recursive calls
    if (s[0] == t[0])
    {
        return 1 + longestCommonSubsequenceMemoization(s.substr(1), t.substr(1), i - 1, j - 1, output);
    }
    else
    {
        int a = longestCommonSubsequenceMemoization(s.substr(1), t, i - 1, j, output);
        int b = longestCommonSubsequenceMemoization(s, t.substr(1), i, j - 1, output);
        int ans = max(a, b);
        output[i][j] = ans;
        return ans;
    }
}

int longestCommonSubsequence(string s, string t)
{
    int **output = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        output[i] = new int[t.length() + 1];
        for (int j = 0; j <= t.length(); j++)
        {
            output[i][j] = -1;
        }
    }
    return longestCommonSubsequenceMemoization(s, t, s.length(), t.length(), output);
}

// Brute Force Approach
int longestCommonSubsequenceBruteForceApproach(string s, string t)
{
    // Base Case
    if (s.empty() || t.empty())
    {
        return 0;
    }
    // Recursive calls
    if (s[0] == t[0])
    {
        return 1 + longestCommonSubsequenceBruteForceApproach(s.substr(1), t.substr(1));
    }
    else
    {
        int a = longestCommonSubsequenceBruteForceApproach(s.substr(1), t);
        int b = longestCommonSubsequenceBruteForceApproach(s, t.substr(1));
        int c = longestCommonSubsequenceBruteForceApproach(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << longestCommonSubsequenceDP(s, t) << endl;
}