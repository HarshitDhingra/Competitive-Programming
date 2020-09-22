#include <bits/stdc++.h>
using namespace std;

int solve(string s) {

  int n = s.length();
  int dp[n + 1][n + 1];

  map<char, int>m;
  vector<int>prev(n);
  vector<int>next(n);

  for (int i = 0; i < n; i++) {

    char ch = s[i];

    if (m[ch] == 0) {
      prev[i] = -1;
    }
    else {
      prev[i] = m[ch];
    }

    m[ch] = i;
  }

  m.clear();

  for (int i = n - 1; i >= 0; i--) {

    char ch = s[i];

    if (m[ch] == 0) {
      next[i] = -1;
    }
    else {
      next[i] = m[ch];
    }

    m[ch] = i;
  }

  for (int diagonal = 0; diagonal < n; diagonal++) {

    int i = 0;
    int j = diagonal;

    while (j < n) {

      if (diagonal == 0) {
        dp[i][j] = 1;
      }
      else if (diagonal == 1) {
        dp[i][j] = 2;
      }
      else if (s[i] != s[j]) {
        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
      }
      else {
        int n = next[i];
        int p = prev[j];

        if (n > p) {
          dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
        }
        else if (n == p) {
          dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
        }
        else {
          dp[i][j] = 2 * dp[i + 1][j - 1] - dp[n + 1][p - 1];
        }
      }

      i++; j++;
    }
  }

  return dp[0][n - 1];
}

int main() {

  string s;
  cin >> s;

  cout << solve(s);

  return 0;
}