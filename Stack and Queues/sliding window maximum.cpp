#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, int n, int k) {

    vector<int>ng(n);
    stack<int>s;
    s.push(n - 1);
    ng[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {

        while (s.size() > 0 && v[s.top()] < v[i]) {
            s.pop();
        }
        if (s.size() != 0) {
            ng[i] = s.top();
        }
        else {
            ng[i] = n;
        }
        s.push(i);
    }

    vector<int>ans(n - k + 1);
    int j = 0;
    for (int i = 0; i <= n - k; i++) {
        if (j < i) {
            j = i;
        }
        while (ng[j] < i + k) {
            j = ng[j];
        }
        ans[i] = v[j];
    }

    for (auto i : ans) {
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
    int k;
    cin >> k;

    solve(v, n, k);

}
