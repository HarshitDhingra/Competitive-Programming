#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        cout << "#" << c << " : " << dp[n] << endl;
        c++;
    }
}
