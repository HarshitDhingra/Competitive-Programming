#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

    int csum = v[0], gans = v[0];
    for (int i = 1; i < n; i++) {

        csum = max(v[i] + csum, v[i]);
        gans = max(gans, csum);
    }
    return gans;
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