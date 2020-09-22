#include <bits/stdc++.h>
using namespace std;

int solve1(vector<int>& v, int n) {

  int obsp = -v[0];
  int ossp = 0;
  int ocsp = 0;

  for (int i = 1; i < n; i++) {
    int nssp, nbsp, ncsp;

    if (ocsp - v[i] > obsp) {
      nbsp = ocsp - v[i];
    }
    else {
      nbsp = obsp;
    }

    if (ossp > ocsp) {
      ncsp = ossp;
    }
    else {
      ncsp = ocsp;
    }

    if (obsp + v[i] > ossp) {
      nssp = obsp + v[i];
    }
    else {
      nssp = ossp;
    }

    ossp = nssp;
    obsp = nbsp;
    ocsp = ncsp;

  }

  return ossp;
}


int solve(vector<int>& v, int n) {

  int bsp = -v[0];
  int ssp = 0;
  int csp = 0;

  for (int i = 1; i < n; i++) {

    bsp = max(bsp, csp - v[i]);

    csp = max(csp, ssp);

    ssp = max(ssp, v[i] + bsp);
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

  cout << solve1(v, n);

  return 0;
}