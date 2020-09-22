#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n, int k) {

    int dp[25][25] = {0};

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1];

            for (int p = 0; p < j; p++)
            {
                int x = v[j] - v[p];

                int y = dp[i - 1][p] + x;

                dp[i][j] = max(dp[i][j], y);
            }
        }
    }

    return dp[k][n - 1];
}

int solve1(vector<int>& v, int n, int k) {

    int dp[25][25] = {0};

    for (int i = 1; i <= k; i++)
    {
        int maxi = INT_MIN;

        for (int j = 1; j < n; j++)
        {
            maxi = max(maxi, dp[i - 1][j - 1] - v[j - 1]);

            dp[i][j] = max(dp[i][j - 1], maxi + v[j]);
        }
    }

    return dp[k][n - 1];
}


int main() {

    int n, k;
    cin >> n;

    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> k;

    cout << solve1(v, n, k);

    return 0;
}