#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, int n) {

    stack<pair<int, int>>s;
    vector<int>ans(n);

    s.push({v[0], 0});
    ans[0] = 1;

    for (int i = 1; i < n; i++) {

        while (s.size() > 0 and v[i] > s.top().first) {
            s.pop();
        }
        if (s.size() > 0) {
            ans[i] = i - s.top().second;
        }
        else {
            ans[i] = i + 1;
        }
        s.push({v[i], i});
    }

    for (int i : ans) {
        cout << i << "\n";
    }
}

void solve1(vector<int>& v, int n) {

    stack<int>s;
    vector<int>ans(n);

    s.push(0);
    ans[0] = 1;

    for (int i = 1; i < n; i++) {

        while (s.size() > 0 and v[i] > v[s.top()]) {
            s.pop();
        }
        if (s.size() > 0) {
            ans[i] = i - s.top();
        }
        else {
            ans[i] = i + 1;
        }
        s.push(i);
    }

    for (int i : ans) {
        cout << i << "\n";
    }
}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    solve1(v, n);

}
