#include <bits/stdc++.h>
using namespace std;

int solve2(int n, vector<int>& jumps) {
    vector<int>dp(n + 1, 10000);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= jumps[i]; j++) {
            if (i + j <= n)
                dp[i] = min(dp[i], 1 + dp[i + j]);
        }
    }
    return dp[0];
}

int main() {

    int n;
    cin >> n;
    vector<int>jumps(n);
    for (int i = 0; i < n; i++) {
        cin >> jumps[i];
    }

    cout << solve2(n, jumps);

    return 0;
}
