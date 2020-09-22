#include <bits/stdc++.h>
using namespace std;

int solve1(vector<int>& v, int n, int fee) {

  int obsp = -v[0];
  int ossp = 0;

  for (int i = 1; i < n; i++) {
    int nssp, nbsp;

    if (ossp - v[i] > obsp) {
      nbsp = ossp - v[i];
    }
    else {
      nbsp = obsp;
    }

    if (obsp + v[i] - fee > ossp) {
      nssp = obsp + v[i] - fee;
    }
    else {
      nssp = ossp;
    }

    ossp = nssp;
    obsp = nbsp;

  }

  return ossp;
}


int solve(vector<int>& v, int n, int fee) {

  int bsp = -v[0];
  int ssp = 0;

  for (int i = 1; i < n; i++) {

    bsp = max(bsp, ssp - v[i]);
    ssp = max(ssp, v[i] + bsp - fee);
  }

  return ssp;
}


int main() {

  int n;
  cin >> n;

  vector<int>v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int fee;
  cin >> fee;

  cout << solve1(v, n, fee);

  return 0;
}