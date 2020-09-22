#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

    int ans = 0;
    int currentp = 0;
    int least = INT_MAX;

    for (int i = 0; i < n; i++) {

        least = min(least, v[i]);

        currentp = v[i] - least;

        ans = max(ans, currentp);
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

    cout << solve(v, n);

    return 0;
}