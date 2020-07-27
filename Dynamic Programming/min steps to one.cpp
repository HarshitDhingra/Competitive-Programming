#include <bits/stdc++.h>
using namespace std;

int min_steps_top_down(int n, int dp[])
{
    if (n == 1)
        return 0;

    if (dp[n] != 0)
        return dp[n];

    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;

    if (n % 2 == 0) {
        ans1 = min_steps_top_down(n / 2, dp);
    }
    if (n % 3 == 0) {
        ans2 = min_steps_top_down(n / 3, dp);
    }
    ans3 = min_steps_top_down(n - 1, dp);

    int ans = 1 + min(ans1, min(ans2, ans3));
    dp[n] = ans;

    return ans;
}

int min_steps_top_down_botto_up(int n)
{
    int dp[1000];
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int ans1, ans2, ans3;
        ans1 = ans2 = ans3 = INT_MAX;
        if (i % 2 == 0) {
            ans1 = dp[i / 2];
        }
        if (i % 3 == 0) {
            ans2 = dp[i / 3];
        }
        ans3 = dp[i - 1];

        dp[i] = 1 + min(ans1, min(ans2, ans3));
    }
    return dp[n];
}

int main() {
    int dp[1000] = {0};
    int n;
    cin >> n;
    cout << min_steps_top_down(n, dp) << endl;
    cout << min_steps_top_down_botto_up(n);
}
