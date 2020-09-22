#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {

  double x = (double)a.first / a.second;
  double y = (double)b.first / b.second;

  return x > y;
}

double solve(vector<pair<int, int>>& v, int target) {
  int n = v.size();
  sort(v.begin(), v.end(), cmp);

  int sum = 0;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    if (sum == target) {
      break;
    }
    if (sum + v[i].second <= target) {
      ans += v[i].first;
      sum += (double)v[i].second;
    }
    else {
      int rem = target - sum;
      ans += ((double)rem / v[i].second) * v[i].first;
      sum += rem;
    }
  }

  return ans;
}

int main() {

  int n;
  cin >> n;
  vector<int>value(n);
  vector<int>weight(n);
  for (int i = 0; i < n; i++) {
    cin >> value[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }
  vector<pair<int, int>>v(n);
  for (int i = 0; i < n; i++) {
    v[i] = {value[i], weight[i]};
  }
  int target;
  cin >> target;

  double ans = (double) solve(v, target);
  if (ans == (int)ans)cout << fixed << setprecision(1) << ans;
  else printf("%.6g", ans);

  return 0;
}