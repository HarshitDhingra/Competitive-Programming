#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

    int dp[n][n] = {0};

    for (int d = 1; d < n; d++) {
        int i = 1;
        int j = d;
        while (j < n) {

            if (d == 1) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
                }
            }

            i++; j++;
        }
    }

    return dp[1][n - 1];
}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << solve(v, n);

    return 0;
}