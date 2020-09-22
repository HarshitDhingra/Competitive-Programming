#include <bits/stdc++.h>
using namespace std;

class Pair {
public:
  int i;
  int j;
  string path;

  Pair(int x, int y, string t) {
    i = x;
    j = y;
    path = t;
  }

};

int solve(vector<int>& v, vector<int>& w, int n, int weight) {

  int dp[n + 1][weight + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= weight; j++) {

      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
      else {
        dp[i][j] = dp[i - 1][j];

        if (j - w[i - 1] >= 0) {
          dp[i][j] = max(dp[i][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
        }
      }
    }
  }

  cout << dp[n][weight] << endl;

  queue<Pair>q;
  q.push(Pair(n, weight, ""));

  while (!q.empty()) {

    Pair temp = q.front();
    q.pop();

    int ci = temp.i;
    int cj = temp.j;

    if (ci == 0 || cj == 0) {
      cout << temp.path << endl;
      continue;
    }

    if (dp[ci - 1][cj] == dp[ci][cj]) {
      q.push(Pair(ci - 1, cj, temp.path));
    }

    if (cj - w[ci - 1] >= 0 && (dp[ci - 1][cj - w[ci - 1]] + v[ci - 1]) == dp[ci][cj]) {
      q.push(Pair(ci - 1, cj - w[ci - 1], to_string(ci - 1) + " " + temp.path));
    }

  }

  return 0;
}

int main() {

  int n;
  cin >> n;
  vector<int>v(n);
  vector<int>w(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  int weight;
  cin >> weight;

  solve(v, w, n, weight);

  return 0;
}