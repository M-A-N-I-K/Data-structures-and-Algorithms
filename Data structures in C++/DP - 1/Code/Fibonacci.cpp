#include <iostream>

using namespace std;

// Brute Force Approach
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fib(n - 1);
    int b = fib(n - 2);
    return a + b;
}

// Dynamic Programming
int fib3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}
// Memoization approach
int fib_Helper(int n, int *ans)
{
    if (n <= 1)
    {
        return n;
    }
    // Check if output already exists
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fib_Helper(n - 1, ans);
    int b = fib_Helper(n - 2, ans);

    // Save the output for future use
    ans[n] = a + b;

    // Return the final answer
    return ans[n];
}

int fib2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fib_Helper(n, ans);
}

int main()
{
    int n = 6;
    cout << fib3(n) << endl;
}