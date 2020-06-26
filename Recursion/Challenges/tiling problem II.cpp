#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


int rec(int n, int m, vector<int>& dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;
    ans += rec(n - 1, m, dp) + rec(n - m, m, dp);

    dp[n] = ans;

    return ans;
}
long long rec1(long long n, long long m)
{
    if (n < m)
    {
        return 1;
    }
    vector<long long>dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        long long subans1 = 0;
        subans1 = dp[i - 1];
        long long subans2 = 0;
        if (i - m >= 0)
            subans2 = dp[i - m];

        dp[i] = (subans1 % mod + subans2 % mod) % mod ;
    }
    return dp[n];

}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        // vector<int>dp(n+1,-1);
        long long ans = rec1(n, m);
        cout << ans << endl;
    }
}
