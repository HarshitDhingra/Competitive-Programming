#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

  int dp[n + 1];

  int maxlen = 1;

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {

      if (v[i] > v[j]) {

        dp[i] = max(dp[i], 1 + dp[j]);
      }

      maxlen = max(maxlen, dp[i]);
    }
  }
  return maxlen;
}

int main() {

  int n;
  cin >> n;

  vector<int>v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << solve(v, n);

  return 0;
}