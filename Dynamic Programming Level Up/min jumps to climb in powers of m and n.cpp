#include <bits/stdc++.h>
using namespace std;

int solve(int l, int m, int n) {

    int dp[l + 1];
    dp[0] = 0;
    for (int i = 1; i <= l; i++) {
        dp[i] = INT_MAX;
        for (int j = 20; j >= 0; j--) {
            int x = pow(m, j);

            if (i - x >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - x]);
            }
        }

        for (int j = 20; j >= 0; j--) {
            int x = pow(n, j);

            if (i - x >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - x]);
            }
        }
    }

    return dp[l];
}

int main() {

    int l, m, n;
    cin >> l >> m >> n;

    cout << solve(l, m, n);

}
