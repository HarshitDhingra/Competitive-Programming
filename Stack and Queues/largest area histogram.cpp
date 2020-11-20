#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

    stack<int>s;
    vector<int>nsr(n);
    vector<int>nsl(n);

    nsl[0] = 0;
    nsr[n - 1] = n - 1;
    s.push(0);

    for (int i = 1; i < n; i++) {

        while (s.size() > 0 and v[i] <= v[s.top()]) {
            s.pop();
        }
        if (s.size() != 0) {
            nsl[i] = s.top() + 1;
        }
        else {
            nsl[i] = 0;
        }
        s.push(i);
    }

    stack<int>hhh;
    s = hhh;
    s.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {

        while (s.size() > 0 and v[i] <= v[s.top()]) {
            s.pop();
        }
        if (s.size() != 0) {
            nsr[i] = s.top() - 1;
        }
        else {
            nsr[i] = n - 1;
        }
        s.push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        int lw = nsl[i];
        int rw = nsr[i];
        //cout<<lw<<" "<<rw<<endl;

        int temp = v[i] * (rw - lw + 1);

        ans = max(ans, temp);
    }
    return ans;
}

int solve1(vector<int>& v, int n) {

    stack<int>s;
    vector<int>nsr(n);
    vector<int>nsl(n);

    nsl[0] = -1;
    s.push(0);

    for (int i = 1; i < n; i++) {

        while (s.size() > 0 and v[i] <= v[s.top()]) {
            s.pop();
        }
        if (s.size() != 0) {
            nsl[i] = s.top();
        }
        else {
            nsl[i] = -1;
        }
        s.push(i);
    }

    stack<int>hhh;
    s = hhh;
    s.push(n - 1);
    nsr[n - 1] = n;

    for (int i = n - 2; i >= 0; i--) {

        while (s.size() > 0 and v[i] <= v[s.top()]) {
            s.pop();
        }
        if (s.size() != 0) {
            nsr[i] = s.top();
        }
        else {
            nsr[i] = n;
        }
        s.push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        int lw = nsl[i];
        int rw = nsr[i];

        int temp = v[i] * (rw - lw - 1);

        ans = max(ans, temp);
    }
    return ans;
}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << solve1(v, n);

}
