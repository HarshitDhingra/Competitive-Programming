#include <iostream>
using namespace std;

int solve(int n) {

    int dp[n + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int inside = i - 1;
        int outside = 0;

        while (outside <= i - 1) {

            dp[i] += dp[inside] * dp[outside];

            outside++;
            inside--;
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << solve(n);
}
