#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&v, int target) {

  int n = v.size();
  vector<int>dp(target + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < n; j++) {
      if (i - v[j] >= 0)
        dp[i] += dp[i - v[j]];
    }
  }
  return dp[target];
}

int main() {

  int n;
  cin >> n;
  vector<int>v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int target;
  cin >> target;

  int ans = solve(v, target);
  cout << ans;

  return 0;
}