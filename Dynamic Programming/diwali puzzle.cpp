#include <bits/stdc++.h>
#define mod 1000003;
using namespace std;

int n, x;
int dp[105][5][105];

int rec(int i, int prev, int count)
{
    if (i == n) {
        return ((count == x) ? 1 : 0);
    }

    if (dp[i][prev][count] != -1) {
        return dp[i][prev][count];
    }

    int ans = 0;
    if (prev == 1)
    {
        ans += rec(i + 1, 1, count + 1);
    }
    else
    {
        ans += rec(i + 1, 1, count);
    }
    ans += rec(i + 1, 0, count);
    ans = ans % mod;

    return dp[i][prev][count] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        memset(dp, -1, sizeof(dp));

        int ans = (rec(1, 0, 0) + rec(1, 1, 0)) % mod;
        cout << ans << endl;
    }
}
