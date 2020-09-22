#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

  int dp[n + 1];
  int maxsum = 0;

  for (int i = 0; i < n; i++) {

    int tempsum = 0;
    for (int j = 0; j < i; j++) {

      if (v[i] >= v[j]) {

        tempsum = max(tempsum, dp[j]);
      }
    }
    dp[i] = v[i] + tempsum;
    maxsum = max(maxsum, dp[i]);
  }
  return maxsum;
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