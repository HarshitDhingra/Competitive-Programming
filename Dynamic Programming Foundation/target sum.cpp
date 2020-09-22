#include <bits/stdc++.h>
using namespace std;

int dp[105][1005];

bool rec(int i, int sum, vector<int>& v, int n, int target) {

  if (i == n) {
    if (sum == target) {
      return true;
    }
    else {
      return false;
    }
  }

  if (dp[i][sum] != -1) {
    return dp[i][sum];
  }

  bool ans;
  ans = rec(i + 1, sum, v, n, target) + rec(i + 1, sum + v[i], v, n, target);
  dp[i][sum] = ans;

  return ans;
}

bool solve(vector<int>&v, int target) {
  int n = v.size();
  bool dp[n + 1][target + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = true;
      }
      else if (j == 0) {
        dp[i][j] = true;
      }
      else if (i == 0) {
        dp[i][j] = false;
      }
      else {
        if (j - v[i - 1] >= 0) {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
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

  memset(dp, -1, sizeof dp);
  int n;
  cin >> n;
  vector<int>v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int target;
  cin >> target;

  bool ans = solve(v, target);

  if (ans)cout << "true";
  else cout << "false";

  return 0;
}
