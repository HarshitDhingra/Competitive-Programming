#include <bits/stdc++.h>
using namespace std;

long long friendsPairing(int n)
{
    vector<long long>dp(n + 1, 0);

    dp[1] = 1;
    dp[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] += dp[i - 1] + ((i - 1) * dp[i - 2]);
    }

    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << friendsPairing(n) << endl;
    }

    return 0;

}
