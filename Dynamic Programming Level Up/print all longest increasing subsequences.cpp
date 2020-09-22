#include <bits/stdc++.h>
using namespace std;

class Pair {
public:
  int l;
  int i;
  int v;
  string path;

  Pair(int x, int y, int z, string s) {
    l = x;
    i = y;
    v = z;
    path = s;
  }

};

int solve(vector<int>& v, int n) {

  vector<int>dp(n);
  int maxi = 0;

  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = 0; j < i; j++) {
      if (v[i] >= v[j])
        temp = max(temp, dp[j]);
    }
    dp[i] = temp + 1;
    maxi = max(maxi, dp[i]);
  }
  cout << maxi << endl;
  queue<Pair>q;
  for (int i = 0; i < n; i++) {
    if (dp[i] == maxi) {
      q.push(Pair(dp[i], i, v[i], to_string(v[i])));
    }
  }

  while (q.size() > 0) {

    Pair temp = q.front();
    q.pop();

    if (temp.l == 1) {
      cout << temp.path << endl;
    }

    for (int k = temp.i - 1; k >= 0; k--) {
      if (temp.l - 1 == dp[k] && v[k] <= temp.v) {
        string x = to_string(v[k]);
        q.push(Pair(dp[k], k, v[k], x + " -> " + temp.path));
      }
    }

  }


  return maxi;
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