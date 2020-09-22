#include <bits/stdc++.h>
using namespace std;

int solve(int v[][3], int n) {

    int r = v[0][0];
    int b = v[0][1];
    int g = v[0][2];

    for (int i = 1; i < n; i++) {

        int nr = v[i][0] + min(b, g);
        int nb = v[i][1] + min(r, g);
        int ng = v[i][2] + min(r, b);

        r = nr;
        b = nb;
        g = ng;
    }
    return min(r, min(b, g));
}

int solve1(int v[][3], int n) {

    int dp[n + 1][3];

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for (int i = 1; i < n; i++) {

        dp[i][0] = v[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i][2] + min(dp[i - 1][0], dp[i - 1][1]);

    }
    int ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    return ans;
}

int main() {

    int n;
    cin >> n;
    int v[1001][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    cout << solve1(v, n);

    return 0;
}