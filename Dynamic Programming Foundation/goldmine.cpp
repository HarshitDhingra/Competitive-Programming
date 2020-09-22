#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int mat[][105]) {
  int dp[105][105];
  int maxi = -1;
  dp[n][m] = 0;

  for (int j = m - 1; j >= 0; j--) {
    for (int i = n - 1; i >= 0; i--) {
      if (j == m - 1) {
        dp[i][j] = mat[i][j];
      }
      else if (i == n - 1) {
        dp[i][j] = mat[i][j] + max(dp[i - 1][j + 1], dp[i][j + 1]);
      }
      else if (i == 0) {
        dp[i][j] = mat[i][j] + max(dp[i + 1][j + 1], dp[i][j + 1]);
      }
      else {
        dp[i][j] = mat[i][j] + max(dp[i][j + 1], max(dp[i + 1][j + 1], dp[i - 1][j + 1]));
      }
      maxi = max(maxi, dp[i][j]);
    }
  }

  return maxi;
}

int main() {

  int n, m;
  cin >> n >> m;
  int mat[105][105];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  cout << solve(n, m, mat);

  return 0;
}
