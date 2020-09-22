#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

  int lis[n + 1], lds[n + 1];

  for (int i = 0; i < n; i++) {

    int temp = 0;
    for (int j = 0; j < i; j++) {

      if (v[i] >= v[j]) {

        temp = max(temp, lis[j]);
      }
    }
    lis[i] = 1 + temp;
  }

  for (int i = n - 1; i >= 0; i--) {

    int temp = 0;
    for (int j = i + 1; j < n; j++) {

      if (v[i] >= v[j]) {

        temp = max(temp, lds[j]);
      }
    }
    lds[i] = 1 + temp;
  }

  int maxlen = 0;
  for (int i = 0; i < n; i++) {
    maxlen = max(maxlen, lis[i] + lds[i] - 1);
  }

  return maxlen;
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