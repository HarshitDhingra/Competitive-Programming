#include <bits/stdc++.h>
using namespace std;

class Pair {
public:
  int i;
  int s;
  int v;
  string path;

  Pair(int x, int y, int z, string t) {
    i = x;
    s = y;
    v = z;
    path = t;
  }

};

int solve(vector<int>& v, int n) {

  vector<int>dp(n);
  dp[n - 1] = 0;

  for (int i = n - 2; i >= 0; i--) {
    if (v[i] == 0) {
      dp[i] = INT_MAX;
    }
    else {
      int temp = INT_MAX;
      for (int j = 1; j <= v[i]; j++) {
        if (i + j < n)
          temp = min(temp, dp[i + j]);
      }
      dp[i] = temp + 1;
    }
  }
  cout << dp[0] << endl;

  queue<Pair>q;
  q.push(Pair(0, v[0], dp[0], to_string(0)));

  while (!q.empty()) {

    Pair temp = q.front();
    q.pop();

    if (temp.v == 0) {
      cout << temp.path + " ." << endl;
    }

    for (int j = 1; j <= temp.s; j++) {
      if (temp.v - 1 == dp[temp.i + j] && temp.i + j < n) {
        q.push(Pair(temp.i + j, v[temp.i + j], dp[temp.i + j], temp.path + " -> " + to_string(temp.i + j)));
      }
    }
  }

  return dp[0];
}

int main() {

  int n;
  cin >> n;
  vector<int>v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  solve(v, n);

  return 0;
}