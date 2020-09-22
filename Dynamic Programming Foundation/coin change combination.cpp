#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&v, int target) {

  int n = v.size();
  vector<int>dp(target + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= target; j++) {
      if (j - v[i] >= 0)
        dp[j] += dp[j - v[i]];
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