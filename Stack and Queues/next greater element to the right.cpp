#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, int n) {

    stack<int>s;
    vector<int>ans(n);

    s.push(v[n - 1]);
    ans[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {

        while (s.size() > 0 and s.top() < v[i]) {
            s.pop();
        }
        if (s.size() > 0) {
            ans[i] = s.top();
        }
        else {
            ans[i] = -1;
        }
        s.push(v[i]);
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

    solve(v, n);

}
