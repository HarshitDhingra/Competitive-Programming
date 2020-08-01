#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int dp[1001][1001];

int ways(int n, int m)
{
    if (dp[0][0] == -1) {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -1)
                continue;

            dp[i][j] = 0;

            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if (i == 0) {
                dp[i][j] = (dp[i][j - 1] == -1) ? 0 : dp[i][j - 1];
            }
            else if (j == 0) {
                dp[i][j] = (dp[i - 1][j] == -1) ? 0 : dp[i - 1][j];
            }
            else {
                dp[i][j] += (dp[i - 1][j] == -1) ? 0 : dp[i - 1][j];
                dp[i][j] += (dp[i][j - 1] == -1) ? 0 : dp[i][j - 1];
            }
            dp[i][j] = dp[i][j] % mod;
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    int n, m, p;
    memset(dp, 0, sizeof(dp));
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    cout << ways(n, m);

}
