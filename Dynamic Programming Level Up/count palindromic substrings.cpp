#include <bits/stdc++.h>
using namespace std;

int solve(string s) {

  int n = s.length();
  int ans = 0;
  int dp[n + 1][n + 1];

  for (int diagonal = 0; diagonal < n; diagonal++) {

    int i = 0;
    int j = diagonal;

    while (j < n) {

      if (diagonal == 0) {
        dp[i][j] = 1;
      }
      else if (diagonal == 1) {
        if (s[i] == s[j]) {
          dp[i][j] = 1;
        }
        else {
          dp[i][j] = 0;
        }
      }
      else {
        if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
          dp[i][j] = 1;
        }
        else {
          dp[i][j] = 0;
        }
      }

      if (dp[i][j]) {
        ans++;
      }

      i++; j++;
    }
  }
  return ans;
}

int main() {

  string s1;
  cin >> s1;

  cout << solve(s1);

  return 0;
}