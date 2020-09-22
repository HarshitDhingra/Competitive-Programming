#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

    int least = v[0];
    int dp1[n + 1] = {0};

    for (int i = 1; i < n; i++) {

        least = min(least, v[i]);

        int maxpist = v[i] - least;

        dp1[i] = max(dp1[i - 1], maxpist);
    }

    int maxi = v[n - 1];
    int dp2[n + 1] = {0};

    for (int i = n - 2; i >= 0; i--) {

        maxi = max(maxi, v[i]);

        int maxpisat = maxi - v[i];

        dp2[i] = max(dp2[i + 1], maxpisat);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {

        ans = max(ans, dp1[i] + dp2[i]);
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