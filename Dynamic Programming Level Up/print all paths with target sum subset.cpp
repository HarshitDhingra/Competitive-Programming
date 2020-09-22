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

int solve(vector<int>& v, int n, int target) {

  bool dp[n + 1][target + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = true;
      }
      else if (i == 0) {
        dp[i][j] = false;
      }
      else if (j == 0) {
        dp[i][j] = true;
      }
      else {
        dp[i][j] = dp[i - 1][j];

        if (j - v[i - 1] >= 0) {
          dp[i][j] += dp[i - 1][j - v[i - 1]];
        }
      }
    }
  }

  if (dp[n][target])
    cout << "true\n";
  else
    cout << "false\n";

  queue<Pair>q;
  q.push(Pair(n, target, ""));

  while (!q.empty()) {

    Pair temp = q.front();
    q.pop();

    int ci = temp.i;
    int cj = temp.j;

    if (ci == 0 or cj == 0) {
      cout << temp.path << endl;
      continue;
    }

    if (cj - v[temp.i - 1] >= 0 && dp[ci - 1][cj - v[temp.i - 1]] == true) {
      q.push(Pair(ci - 1, cj - v[temp.i - 1], to_string(temp.i - 1) + " " + temp.path));
    }

    if (ci - 1 >= 0 && dp[ci - 1][cj] == true) {
      q.push(Pair(ci - 1, cj, temp.path));
    }

  }

  return 0;
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

  solve(v, n, target);

  return 0;
}