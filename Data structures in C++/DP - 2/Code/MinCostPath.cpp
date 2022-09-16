/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :

The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.

Output format :

Print the minimum cost to reach the destination.

Constraints :

1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec

Sample Input 1 :

3 4
3 4 1 2
2 1 8 9
4 7 8 1

Sample Output 1 :

13

Sample Input 2 :

3 4
10 6 9 0
-23 8 9 90
-200 0 89 200

Sample Output 2 :

76

Sample Input 3 :

5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4
9 6 2 -10 7 4
10 -2 0 5 5 7

Sample Output 3 :

18
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int minCostPathDP(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    // Last Cell i.e destination
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // Fill last row in right to left manner
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // Fill last column (bottom to top)
    for (int j = m - 2; j >= 0; j--)
    {
        output[j][n - 1] = output[j + 1][n - 1] + input[j][n - 1];
    }

    // Fill remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }
    return output[0][0];
}

int minCostPathMemoization(int **input, int m, int n, int row, int col, int **output)
{
    if (row == m - 1 && col == n - 1)
    {
        return input[row][col];
    }
    if (row >= m || col >= n)
    {
        return INT_MAX;
    }
    // Check if answer already exists
    if (output[row][col] != -1)
    {
        return output[row][col];
    }
    // Recursive calls
    int down = minCostPathMemoization(input, m, n, row + 1, col, output);
    int rightSide = minCostPathMemoization(input, m, n, row, col + 1, output);
    int diagonal = minCostPathMemoization(input, m, n, row + 1, col + 1, output);

    // Small Calculation
    int ans = input[row][col] + min(min(down, rightSide), diagonal);

    // Save the answer for future use
    output[row][col] = ans;
    return ans;
}

int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return minCostPathMemoization(input, m, n, 0, 0, output);
}

int minCostPathHelper(int **input, int m, int n, int row, int col)
{
    if (row == m - 1 && col == n - 1)
    {
        return input[row][col];
    }
    int rightSide = INT_MAX, down = INT_MAX, diagonal = INT_MAX;
    if (row + 1 < m)
    {
        down = minCostPathHelper(input, m, n, row + 1, col);
    }
    if (col + 1 < n)
    {
        rightSide = minCostPathHelper(input, m, n, row, col + 1);
    }
    if (row + 1 < m && col + 1 < n)
    {
        diagonal = minCostPathHelper(input, m, n, row + 1, col + 1);
    }
    int ans = input[row][col] + min(min(down, rightSide), diagonal);
    return ans;
}
/*
int minCostPath(int **input, int m, int n)
{
    return minCostPathHelper(input, m, n, 0, 0);
}
*/
int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPathDP(arr, n, m) << endl;
}