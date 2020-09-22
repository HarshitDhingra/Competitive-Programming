#include <bits/stdc++.h>
using namespace std;

long long solve(string s) {

  int n = s.length();
  long long dp[n + 1];
  map<char, int>m;
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {

    char ch = s[i - 1];

    if (m[ch] == 0) {
      dp[i] = 2 * dp[i - 1];
    }
    else {
      dp[i] = 2 * dp[i - 1] - dp[m[ch] - 1];
    }
    m[ch] = i;
  }

  return dp[n] - 1;
}

int main() {

  string s;
  cin >> s;

  cout << solve(s);

  return 0;
}