#include <bits/stdc++.h>
using namespace std;

int dp[1000];

int mincoins_top_down(int coins[], int n, int x)
{
    if (x == 0) {
        return 0;
    }

    if (dp[x] != 0) {
        return dp[x];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= x)
            ans = min(ans, 1 + mincoins_top_down(coins, n, x - coins[i]));
    }
    dp[x] = ans;
    return ans;
}

int mincoins_bottom_up(int coins[], int n, int x)
{
    int dp[100];
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i >= coins[j]) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return dp[x];
}

int main() {
    int coins[] = {1, 7, 10};
    cout << mincoins_top_down(coins, 3, 15) << endl;
    cout << mincoins_bottom_up(coins, 3, 15);
}
