#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

    int dp[n][n] = {0};
    memset(dp, 0, sizeof(dp));

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {

                int temp = v[i];
                temp *= i - 1 >= 0 ? v[i - 1] : 1;
                temp *= i + 1 <= n - 1 ? v[i + 1] : 1;

                dp[i][j] = temp;
            }
            else {

                for (int k = i; k <= j; k++) {

                    int x = (k - 1 >= i) ? dp[i][k - 1] : 0;
                    int y = (k + 1 <= j) ? dp[k + 1][j] : 0;

                    int cost = v[k];
                    cost *= i - 1 >= 0 ? v[i - 1] : 1;
                    cost *= j + 1 <= n - 1 ? v[j + 1] : 1;

                    dp[i][j] = max(dp[i][j], x + y + cost);
                }

            }

            i++; j++;
        }

    }

    return dp[0][n - 1];
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