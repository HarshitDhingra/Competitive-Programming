#include <iostream>
using namespace std;

long long solve(int n) {

    long long dp[n + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int l = 0;
        int r = i - 1;

        while (r >= 0) {

            dp[i] += dp[r] * dp[l];

            l++;
            r--;
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << solve(n);
}
