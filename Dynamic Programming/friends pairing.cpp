#include <bits/stdc++.h>
using namespace std;

int dp[100];

int friend_pairing_top_down(int n)
{
    if (n <= 1) {
        return 1;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    int ans = 0;
    ans += friend_pairing_top_down(n - 1) + ((n - 1) * friend_pairing_top_down(n - 2) );

    dp[n] = ans;

    return ans;
}

int friendsPairing_bottom_up(int n)
{
    vector<int>dp(n + 1, 0);

    dp[1] = 1;
    dp[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] += dp[i - 1] + ((i - 1) * dp[i - 2]);
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << friend_pairing_top_down(n) << endl;
    cout << friendsPairing_bottom_up(n);

}
