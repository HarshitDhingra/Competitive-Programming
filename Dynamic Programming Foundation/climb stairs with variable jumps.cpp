#include <bits/stdc++.h>
using namespace std;

int solve1(int n, vector<int>& jumps) {

    vector<int>dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j + jumps[j] >= i) {
                dp[i] += dp[j];
            }
        }
    }
    return dp[n];
}

int solve2(int n, vector<int>& jumps) {
    vector<int>dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= jumps[i]; j++) {
            if (i + j <= n)
                dp[i] += dp[i + j];
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
