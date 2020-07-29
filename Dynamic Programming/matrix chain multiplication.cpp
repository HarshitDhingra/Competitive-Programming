#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int mcm_top_down(int p[], int i, int j)
{
    if (i == j) {
        return 0;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int subans = mcm_top_down(p, i, k) + mcm_top_down(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        ans = min(ans, subans);
    }
    dp[i][j] = ans;

    return ans;
}

int mcm_bottom_up(int p[], int n)
{
    int dp[100][100];

    for (int diagonal = 1; diagonal < n; diagonal++)
    {
        int i = 1;
        int j = diagonal;
        while (j < n)
        {
            dp[i][j] = INT_MAX;

            if (i == j) {
                dp[i][j] = 0;
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    int subans = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    dp[i][j] = min(dp[i][j], subans);
                }
            }
            i++; j++;
        }
    }
    return dp[1][n - 1];
}

int main() {
    int p[] = {40, 20, 30, 10, 30};
    int n = sizeof(p) / sizeof(int);

    cout << mcm_top_down(p, 1, n - 1) << endl;
    cout << mcm_bottom_up(p, n);
}
