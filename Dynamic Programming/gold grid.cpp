#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1002][1002];

void prefix_sum()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0) {
                continue;
            }
            else if (i == 0) {
                dp[i][j] += dp[i][j - 1];
            }
            else if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            }
            else {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }
}

int goldgrid(int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ans1 = dp[i][j];
            int ans2 = dp[i][n - 1] - dp[i][j];
            int ans3 = dp[n - 1][j] - dp[i][j];
            int ans4 = dp[n - 1][n - 1] - ans1 - ans2 - ans3;
            int subans = min(ans1, min(ans2, min(ans3, ans4)));
            ans = max(ans, subans);
        }
    }
    return ans;
}

int main() {
    int m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = 1;
    }

    prefix_sum();
    cout << goldgrid(n);

    return 0;
}
