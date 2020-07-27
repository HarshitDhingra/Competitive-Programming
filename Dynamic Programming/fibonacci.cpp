#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int fib_top_down(int n, int dp[])
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != 0)
        return dp[n];

    int ans = fib_top_down(n - 1, dp) + fib_top_down(n - 2, dp);
    dp[n] = ans;

    return ans;
}

int fib_bottom_up(int n)
{
    int dp[100] = {0};
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fib_space_opt(int n)
{
    if (n == 0 || n == 1)
        return n;

    int a = 0, b = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int dp[1000] = {0};
    int n;
    cin >> n;
    cout << fib(n) << endl;
    cout << fib_top_down(n, dp) << endl;
    cout << fib_bottom_up(n) << endl;
    cout << fib_space_opt(n) << endl;
}
