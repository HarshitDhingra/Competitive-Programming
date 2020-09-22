#include<bits/stdc++.h>
using namespace std;

int solve(string pattern, string s) {

    int n = pattern.length();
    int m = s.length();

    bool dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if (i == 0) {
                dp[i][j] = 0;
            }
            else if (j == 0) {
                if (pattern[i - 1] == '*') {
                    dp[i][j] = dp[i - 2][j];
                }
                else {
                    dp[i][j] = 0;
                }
            }
            else {

                if (pattern[i - 1] == '*') {

                    dp[i][j] = dp[i - 2][j];

                    if (pattern[i - 2] == s[j - 1] || pattern[i - 2] == '.') {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
                else if (pattern[i - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    if (pattern[i - 1] == s[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
    }

    return dp[n][m];
}

int main() {

    string s, pattern;
    cin >> s >> pattern;

    int ans = solve(pattern, s);

    if (ans) cout << "true";
    else cout << "false";

    return 0;
}