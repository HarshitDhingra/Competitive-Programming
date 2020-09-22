#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&value, vector<int>& weight, int target) {
  int n = value.size();
  int dp[n + 1][target + 1] = {0};

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      if (j == 0 || i == 0) {
        dp[i][j] = 0;
      }
      else {
        if (j - weight[i - 1] >= 0) {
          dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
        }
        else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
  }
  return dp[n][target];
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