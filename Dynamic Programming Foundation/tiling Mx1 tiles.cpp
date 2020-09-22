#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m) {

    vector<int>dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] += dp[i - 1];
        if (i - m >= 0) {
            dp[i] += dp[i - m];
        }
    }
    return dp[n];
}

int main() {

    int n, m;
    cin >> n >> m;

    cout << solve(n, m);

    return 0;
}