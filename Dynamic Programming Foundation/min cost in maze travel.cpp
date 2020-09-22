#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int mat[][105]) {
  int dp[105][105];
  dp[n][m] = 0;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i == n - 1 && j == m - 1) {
        dp[i][j] = mat[i][j];
      }
      else if (i == n - 1) {
        dp[i][j] = mat[i][j] + dp[i][j + 1];
      }
      else if (j == m - 1) {
        dp[i][j] = mat[i][j] + dp[i + 1][j];
      }
      else {
        dp[i][j] = mat[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  return dp[0][0];
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
