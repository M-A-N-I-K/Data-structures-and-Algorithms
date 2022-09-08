/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :

The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :

The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :

1 <= h <= 24
Time Limit: 1 sec

Sample Input 1:

3

Sample Output 1:

15

Sample Input 2:

4

Sample Output 2:

315

*/
#include <iostream>
#include <cmath>
using namespace std;
// Brute Force Approach
long balancedBTs(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    long mod = (long)(pow(10, 9)) + 7;
    long ans1 = balancedBTs(n - 1);
    long ans2 = balancedBTs(n - 2);
    long temp1 = (ans1 * ans1) % mod;
    long temp2 = (2 * ans1 * ans2) % mod;
    long ans = (temp1 + temp2) % mod;

    return ans;
}
// Memoization
long balancedBTsHelper(int n, long *arr)
{
    if (n <= 1)
    {
        return 1;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    long mod = (long)(pow(10, 9)) + 7;
    long ans1 = balancedBTsHelper(n - 1, arr);
    long ans2 = balancedBTsHelper(n - 2, arr);
    long temp1 = (ans1 * ans1) % mod;
    long temp2 = (2 * ans1 * ans2) % mod;
    arr[n] = (temp1 + temp2) % mod;
    return arr[n];
}
long balancedBTs2(int n)
{
    long *arr = new long[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return balancedBTsHelper(n, arr);
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs2(n);
}