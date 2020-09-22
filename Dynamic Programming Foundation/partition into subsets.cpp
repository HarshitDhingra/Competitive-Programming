#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int k) {

    if (n <= 0 || k <= 0 || n < k) {
        return 0;
    }

    long long dp[k + 1][n + 1];

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0 || i == 0) {
                dp[i][j] = 0;
            }
            else if (j < i) {
                dp[i][j] = 0;
            }
            else if (j == i) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + (i * dp[i][j - 1]);
            }
        }
    }
    return dp[k][n];
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << solve(n, k);

    return 0;
}