#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>>v;
    unordered_map<int, int>count_x;
    unordered_map<int, int>count_y;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        count_x[x]++;
        count_y[y]++;
        v.push_back({x, y});
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        ans += (count_x[x] - 1) * (count_y[y] - 1);
    }
    cout << ans << endl;
}
