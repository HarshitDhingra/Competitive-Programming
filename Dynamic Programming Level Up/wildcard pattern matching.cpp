#include <bits/stdc++.h>
using namespace std;

int solve(string pattern, string s) {

  int n = pattern.length();
  int m = s.length();

  bool dp[n + 1][m + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      char ch = pattern[i - 1];

      if (i == 0 && j == 0) {
        dp[i][j] = 1;
      }
      else if (i == 0) {
        dp[i][j] = 0;
      }
      else if (j == 0) {
        if (ch == '*') {
          dp[i][j] = dp[i - 1][j];
        }
        else {
          dp[i][j] = 0;
        }
      }
      else if (ch == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else if (ch == '*') {

        for (int k = 0; k <= j; k++) {
          dp[i][j] += dp[i - 1][k];
        }

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

  return dp[n][m];
}

int solve_optimised(string pattern, string s) {

  int n = pattern.length();
  int m = s.length();

  bool dp[n + 1][m + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      char ch = pattern[i - 1];

      if (i == 0 && j == 0) {
        dp[i][j] = 1;
      }
      else if (i == 0) {
        dp[i][j] = 0;
      }
      else if (j == 0) {
        if (ch == '*') {
          dp[i][j] = dp[i - 1][j];
        }
        else {
          dp[i][j] = 0;
        }
      }
      else if (ch == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else if (ch == '*') {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
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

  return dp[n][m];
}

int solve2(string pattern, string s) {

  int n = pattern.length();
  int m = s.length();

  bool dp[n + 1][m + 1];

  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {

      if (i == n && j == m) {
        dp[i][j] = 1;
      }
      else if (i == n) {
        dp[i][j] = 0;
      }
      else if (j == m) {
        if (pattern[i] == '*') {
          dp[i][j] = dp[i + 1][j];
        }
        else dp[i][j] = 0;
      }
      else {
        if (pattern[i] == '*') {
          dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
        else if (pattern[i] == '?') {
          dp[i][j] = dp[i + 1][j + 1];
        }
        else if (pattern[i] == s[j]) {
          dp[i][j] = dp[i + 1][j + 1];
        }
        else {
          dp[i][j] = 0;
        }
      }
    }
  }

  return dp[0][0];
}

int main() {

  string s, pattern;
  cin >> s >> pattern;

  int ans = solve2(pattern, s);

  if (ans)cout << "true";
  else cout << "false";

  return 0;
}