#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

  int dp[n + 1] = {0};
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++) {

      dp[i] = max(dp[i], v[j - 1] + dp[i - j]);

    }

  }
  return dp[n];
}

int solve1(vector<int>& v, int n) {

  int dp[n + 1] = {0};
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {

    dp[i] = v[i - 1];

    for (int j = 1; j <= i / 2; j++) {

      dp[i] = max(dp[i], dp[j] + dp[i - j]);

    }

  }
  return dp[n];
}

int main() {

  int n;
  cin >> n;
  vector<int>v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << solve1(v, n);

  return 0;
}