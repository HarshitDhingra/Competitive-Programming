#include <bits/stdc++.h>
using namespace std;

long long solve1(int n)
{
    vector<long long>dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i <= n; i++)
    {
        dp[i] += dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int solve2(int n) {
    vector<int>dp0(n + 1, 0);
    vector<int>dp1(n + 1, 0);
    dp0[1] = 1;
    dp1[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp0[i] = dp1[i - 1];
        dp1[i] = dp1[i - 1] + dp0[i - 1];
    }
    return dp0[n] + dp1[n];
}

int main() {

    int n;
    cin >> n;
    cout << solve2(n) << endl;

    return 0;
}