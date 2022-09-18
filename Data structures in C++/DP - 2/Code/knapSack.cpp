/*
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
Input Format :

The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.

Output Format :

Print the maximum value of V that the thief can steal.

Constraints :

1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec

Sample Input 1 :

4
1 2 4 5
5 4 8 6
5

Sample Output 1 :

13

Sample Input 2 :

5
12 7 11 8 9
24 13 23 15 16
26

Sample Output 2 :

51
*/
#include <iostream>
#include <algorithm>
using namespace std;
// DP Approach
int knapsackDp(int *weight, int *value, int n, int maxWeight)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= maxWeight; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < maxWeight + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = dp[n][maxWeight];
    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

// Memoization Approach
int knapsackHelper(int *weight, int *value, int n, int maxWeight, int **arr)
{
    if (maxWeight == 0 || n == 0)
    {
        return 0;
    }
    if (arr[n][maxWeight] != -1)
    {
        return arr[n][maxWeight];
    }
    if (weight[0] > maxWeight)
    {
        arr[n][maxWeight] = knapsackHelper(weight + 1, value + 1, n - 1, maxWeight, arr);
        return arr[n][maxWeight];
    }
    int a = knapsackHelper(weight + 1, value + 1, n - 1, maxWeight - weight[0], arr) + value[0];
    int b = knapsackHelper(weight + 1, value + 1, n - 1, maxWeight, arr);
    arr[n][maxWeight] = max(a, b);
    return arr[n][maxWeight];
}

int knapsackMemoization(int *weight, int *value, int n, int maxWeight)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            arr[i][j] = -1;
        }
    }
    int ans = knapsackHelper(weight, value, n, maxWeight, arr);
    for (int i = 0; i <= n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return ans;
}

// Brute Force Approach Added
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    if (maxWeight == 0 || n == 0)
    {
        return 0;
    }
    if (weights[0] > maxWeight)
    {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }
    int a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
    int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(a, b);
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}