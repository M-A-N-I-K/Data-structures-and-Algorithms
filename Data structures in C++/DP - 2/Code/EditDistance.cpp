/*
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance

Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note

Strings don't contain spaces

Input Format :

The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.

Output Format :

The first and only line of output contains the edit distance value between the given strings.

Constraints :

1<= m,n <= 10
Time Limit: 1 second

Sample Input 1 :

abc
dc

Sample Output 1 :

2
*/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int editDistanceDP(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        output[0][i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }
    return output[m][n];
}

// Memoization approach
int editDistanceHelper(string s1, string s2, int **output)
{
    int i = s1.length(), j = s2.length();
    if (s1.length() == 0 || s2.length() == 0)
    {
        return max(s1.length(), s2.length());
    }
    if (output[i][j] != -1)
    {
        return output[i][j];
    }
    int ans;
    if (s1[0] == s2[0])
    {
        ans = editDistanceHelper(s1.substr(1), s2.substr(1), output);
    }
    else
    {
        int a = editDistanceHelper(s1.substr(1), s2, output);
        int b = editDistanceHelper(s1, s2.substr(1), output);
        int c = editDistanceHelper(s1.substr(1), s2.substr(1), output);
        ans = min(a + 1, min(b + 1, c + 1));
    }
    output[i][j] = ans;
    return output[s1.length()][s2.length()];
}

int editDistanceMemoization(string s1, string s2)
{
    int **output = new int *[s1.length() + 1];
    for (int i = 0; i <= s1.length(); i++)
    {
        output[i] = new int[s2.length() + 1];
        for (int j = 0; j <= s2.length(); j++)
        {
            output[i][j] = -1;
        }
    }
    return editDistanceHelper(s1, s2, output);
}

// Brute force approach
int editDistance(string s1, string s2)
{
    if (s1.length() == 0 || s2.length() == 0)
    {
        return max(s1.length(), s2.length());
    }
    if (s1[0] == s2[0])
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    else
    {
        int a = editDistance(s1.substr(1), s2);
        int b = editDistance(s1, s2.substr(1));
        int c = editDistance(s1.substr(1), s2.substr(1));
        int ans = min(a + 1, min(b + 1, c + 1));
        return ans;
    }
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
    cout << editDistance(s1, s2) << endl;
}