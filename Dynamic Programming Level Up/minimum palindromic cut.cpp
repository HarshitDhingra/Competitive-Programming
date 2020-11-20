#include <bits/stdc++.h>
using namespace std;

bool ispalin(string s, int i, int j) {

    while (j > i) {

        if (s[i] != s[j]) {
            return false;
        }
        i++; j--;
    }

    return true;
}

int solve(string s) {

    int n = s.length();

    int dp[n + 1][n + 1];

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {
                dp[i][j] = 0;
            }
            else {

                if (ispalin(s, i, j)) {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = INT_MAX;

                    for (int k = i; k < j; k++)
                    {
                        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                    }
                }
            }

            i++; j++;
        }

    }
    return dp[0][n - 1];
}

int solve_optimized(string s) {

    int n = s.length();

    int palin[n + 1][n + 1] = {0};

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {
                palin[i][j] = 1;
            }
            else if (d == 1) {
                palin[i][j] = (s[i] == s[j]) ? 1 : 0;
            }
            else {

                if (s[i] == s[j] and palin[i + 1][j - 1] == 1) {
                    palin[i][j] = 1;
                }
                else {
                    palin[i][j] = 0;
                }

            }

            i++; j++;
        }

    }

    int dp[n + 1][n + 1];

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {
                dp[i][j] = 0;
            }
            else {

                if (palin[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = INT_MAX;

                    for (int k = i; k < j; k++)
                    {
                        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                    }
                }
            }

            i++; j++;
        }

    }
    return dp[0][n - 1];
}

int solve2(string s) {

    int n = s.length();

    int palin[n + 1][n + 1] = {0};

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {
                palin[i][j] = 1;
            }
            else if (d == 1) {
                palin[i][j] = (s[i] == s[j]) ? 1 : 0;
            }
            else {

                if (s[i] == s[j] and palin[i + 1][j - 1] == 1) {
                    palin[i][j] = 1;
                }
                else {
                    palin[i][j] = 0;
                }

            }

            i++; j++;
        }

    }

    int dp[n];
    dp[0] = 0;

    for (int j = 1; j < n; j++) {

        if (palin[0][j]) {
            dp[j] = 0;
        }
        else {
            dp[j] = INT_MAX;

            for (int i = j; i >= 1; i--) {

                if (palin[i][j]) {
                    dp[j] = min(dp[j], 1 + dp[i - 1]);
                }
            }
        }
    }

    return dp[n - 1];
}

int main() {

    string s;
    cin >> s;

    cout << solve2(s);

    return 0;
}