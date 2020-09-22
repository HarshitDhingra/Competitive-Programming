#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>>& v, int n) {

  int lis[n + 1];
  int maxlen = 0;
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {

    int temp = 0;
    for (int j = 0; j < i; j++) {

      if (v[i].second >= v[j].second) {

        temp = max(temp, lis[j]);
      }
    }
    lis[i] = 1 + temp;
    maxlen = max(maxlen, lis[i]);
  }

  return maxlen;
}

int main() {

  int n;
  cin >> n;

  vector<pair<int, int>>v(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = {x, y};
  }

  cout << solve(v, n);

  return 0;
}