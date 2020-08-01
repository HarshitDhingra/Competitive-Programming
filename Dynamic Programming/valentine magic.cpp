#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[5005], b[5005];
int dp[5005][5005];

int rec(int i, int j)
{
    if (i == n) {
        return 0;
    }
    if (j == m) {
        return 100000;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans1 = abs(a[i] - b[j]) + rec(i + 1, j + 1);
    int ans2 = rec(i, j + 1);
    dp[i][j] = min(ans1, ans2);

    return dp[i][j];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    sort(a, a + n);
    sort(b, b + m);

    cout << rec(0, 0);

}
