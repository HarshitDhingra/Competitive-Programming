#include <bits/stdc++.h>
using namespace std;

int solve(string s) {

  int n = s.length();
  int dp[n + 1][n + 1];

  for (int g = 0; g < n; g++) {

    int i = 0;
    int j = g;

    while (j < n) {

      if (g == 0) {
        dp[i][j] = 1;
      }
      else if (g == 1) {
        if (s[i] == s[j]) {
          dp[i][j] = 2;
        }
        else {
          dp[i][j] = 1;
        }
      }
      else if (s[i] == s[j]) {
        dp[i][j] = 2 + dp[i + 1][j - 1];
      }
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }

      i++; j++;
    }
  }

  return dp[0][n - 1];
}

int main() {

  string s1;
  cin >> s1;

  cout << solve(s1);

  return 0;
}