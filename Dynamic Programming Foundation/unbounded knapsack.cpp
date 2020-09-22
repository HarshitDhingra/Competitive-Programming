#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&value, vector<int>& weight, int target) {
  int n = value.size();

  vector<int>dp(target + 1, 0);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= target; j++) {
      if (j - weight[i] >= 0)
        dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);
    }
  }
  return dp[target];
}

int main() {

  int n;
  cin >> n;
  vector<int>value(n);
  vector<int>weight(n);
  for (int i = 0; i < n; i++) {
    cin >> value[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }
  int target;
  cin >> target;

  int ans = solve(value, weight, target);
  cout << ans;

  return 0;
}