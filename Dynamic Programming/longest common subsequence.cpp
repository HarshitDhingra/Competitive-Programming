#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int lcs_top_down(string s1, string s2, int n, int m)
{
    if (n == 0 || m == 0) {
        return 0;
    }

    if (dp[n][m] != 0) {
        return dp[n][m];
    }

    int ans = INT_MIN;
    if (s1[n - 1] == s2[m - 1]) {
        ans = 1 + lcs_top_down(s1, s2, n - 1, m - 1);
    }
    else {
        ans = max(lcs_top_down(s1, s2, n - 1, m), lcs_top_down(s1, s2, n, m - 1));
    }

    dp[n][m] = ans;

    return ans;
}

int lcs_bottom_up(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1] = {0};

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs_top_down(s1, s2, s1.length(), s2.length()) << endl;
    cout << lcs_bottom_up(s1, s2);
}
