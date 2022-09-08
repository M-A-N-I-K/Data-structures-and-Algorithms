/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :

The first and the only line of input contains an integer value, 'N'.

 Output format :

Print the minimum count of numbers required.

Constraints :

0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :

12

Sample Output 1 :

3

Explanation of Sample Output 1 :

12 can be represented as :
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :

9

Sample Output 2 :

1

*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Brute Force Approach
int minCount(int n)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
    {
        return 1;
    }
    if (n <= 3)
    {
        return n;
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        int k = i * i;
        if (k > n)
        {
            break;
        }
        else
        {
            ans = min(1 + minCount(n - k), ans);
        }
    }
    return ans;
}

// Memoization
int minCountHelper(int n, int *arr)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
    {
        return 1;
    }
    if (n <= 3)
    {
        return n;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        int k = i * i;
        if (k > n)
        {
            break;
        }
        else
        {
            ans = min(minCountHelper(n - k, arr) + 1, ans);
            arr[n] = ans;
        }
    }
    return arr[n];
}

int minCount2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minCountHelper(n, ans);
}

int main()
{
    int n;
    cin >> n;
    cout << minCount2(n);
}