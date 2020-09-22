#include <bits/stdc++.h>
using namespace std;

int solve(string s) {

    int n = s.length();
    vector<int>dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] != '0')
            dp[i] += dp[i - 1];

        int digit = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (digit <= 26 && s[i - 1] != '0') {
            dp[i] += i - 2 >= 0 ? dp[i - 2] : 1;
        }
    }
    return dp[n - 1];
}
int solve1(string s) {

    int n = s.length();
    vector<int>dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '0' && s[i] == '0') {
            dp[i] = 0;
        }
        else if (s[i - 1] != '0' && s[i] == '0') {
            int digit = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (digit <= 26) {
                dp[i] = i - 2 >= 0 ? dp[i - 2] : 1;
            } else {
                dp[i] = 0;
            }
        }
        else if (s[i - 1] == '0' && s[i] != '0') {
            dp[i] = dp[i - 1];
        }
        else {
            int digit = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (digit <= 26) {
                dp[i] = dp[i - 1] + (i - 2 >= 0 ? dp[i - 2] : 1);
            } else {
                dp[i] = dp[i - 1];
            }
        }
    }
    return dp[n - 1];
}

int main() {

    string s;
    cin >> s;
    int ans = solve1(s);
    cout << ans;

    return 0;
}