#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<int, int>>& v, int n) {

    sort(v.begin(), v.end());
    vector<pair<int, int>>ans;

    ans.push_back(v[0]);
    int e = v[0].second;

    for (int i = 1; i < n; i++) {

        if (v[i].first > e) {
            ans.push_back(v[i]);
            e = v[i].second;
        }
        else {
            e = max(e, v[i].second);
            ans.back().second = e;
        }
    }

    for (auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }

}

void solve1(vector<pair<int, int>>& v, int n) {

    sort(v.begin(), v.end());
    stack<pair<int, int>>s;

    s.push(v[0]);

    for (int i = 1; i < n; i++) {

        if (v[i].first > s.top().second) {
            s.push(v[i]);
        }
        else {
            s.top().second = max(s.top().second, v[i].second);
        }
    }
    stack<pair<int, int>>ans;

    while (s.size() != 0) {

        ans.push(s.top());
        s.pop();
    }

    while (ans.size() != 0) {

        cout << ans.top().first << " " << ans.top().second << endl;
        ans.pop();
    }

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

    solve1(v, n);

}
