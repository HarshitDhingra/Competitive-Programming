#include <bits/stdc++.h>
using namespace std;

int n, m;
int cost[100][100], dp[100][100];

int min_cost_top_down(int i, int j)
{
    if (i == n - 1 && j == m - 1) {
        return cost[i][j];
    }

    if (i == n || j == m) {
        return INT_MAX;
    }

    int ans = 0;
    ans = cost[i][j] + min(min_cost_top_down(i + 1, j), min_cost_top_down(i, j + 1));

    return dp[i][j] = ans;
}

int min_cost_bottom_up(int n, int m)
{
    int dp[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) {
                dp[i][j] = cost[i][j];
            }
            else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + cost[i][j];
            }
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + cost[i][j];
            }
            else {
                dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    cout << min_cost_top_down(0, 0) << endl;
    cout << min_cost_bottom_up(n, m);
}
