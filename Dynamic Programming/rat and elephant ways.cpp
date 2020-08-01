#include <bits/stdc++.h>
using namespace std;

int rat_ways_bottom_up(int n, int m)
{
    int dp[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][m - 1];
}

int elephant_ways_bottom_up(int n, int m)
{
    int dp[100][100] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if (i == 0) {
                for (int k = 0; k <= j - 1; k++)
                    dp[i][j] += dp[i][k];
            }
            else if (j == 0) {
                for (int k = 0; k <= i - 1; k++)
                    dp[i][j] += dp[k][j];
            }
            else {
                for (int k = 0; k <= i - 1; k++)
                    dp[i][j] += dp[k][j];
                for (int k = 0; k <= j - 1; k++)
                    dp[i][j] += dp[i][k];
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << rat_ways_bottom_up(n, m) << endl;
    cout << elephant_ways_bottom_up(n, m);
}
