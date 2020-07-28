#include <bits/stdc++.h>
using namespace std;

int dp[1000];

int jumps_top_down(int n, int k)
{
    if (n == 0) {
        return 1;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n >= i) {
            ans += jumps_top_down(n - i, k);
        }
    }
    dp[n] = ans;

    return ans;
}

int jumps_bottom_up(int n, int k)
{
    int dp[1000] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
                dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int jumps_bottom_up_1(int n, int k)
{
    int dp[1000] = {0};
    dp[0] = 1;
    int sum = dp[0], last = 0;

    for (int i = 1; i <= k; i++)
    {
        dp[i] = sum;
        sum += dp[i];
    }

    for (int i = k + 1; i <= n; i++)
    {
        sum -= dp[last++];
        dp[i] = sum;
        sum += dp[i];
    }

    return dp[n];
}

int jumps_bottom_up_2(int n, int k)
{
    int dp[100] = {0};
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    return dp[n];
}

int main() {
    cout << jumps_top_down(30, 6) << endl;
    cout << jumps_bottom_up(30, 6) << endl;
    cout << jumps_bottom_up_1(30, 6) << endl;
    cout << jumps_bottom_up_2(30, 6);
}
