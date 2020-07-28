#include <bits/stdc++.h>
using namespace std;

int dp[1000];

int rodcutting_top_down(int price[], int n)
{
    if (n == 0) {
        return 0;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int subans = price[i - 1] + rodcutting_top_down(price, n - i);
        ans = max(ans, subans);
    }

    dp[n] = ans;
    return ans;
}

int rodutting_bottom_up(int price[], int n)
{
    int dp[1000] = {0};
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(int);

    cout << rodcutting_top_down(price, n) << endl;
    cout << rodutting_bottom_up(price, n);
}
