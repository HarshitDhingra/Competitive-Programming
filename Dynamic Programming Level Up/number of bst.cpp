#include <iostream>
using namespace std;

int solve(int n) {

    int dp[n + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int solve1(int n) {

    int dp[n + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int l = 0;
        int r = i - 1;

        while (l <= i - 1) {
            dp[i] += dp[l] * dp[r];
            l++;
            r--;
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << solve1(n);
}
