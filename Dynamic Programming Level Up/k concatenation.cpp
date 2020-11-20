#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& v, int n) {

    int csum = v[0], gans = v[0];
    for (int i = 1; i < n; i++) {

        csum = max(v[i] + csum, v[i]);
        gans = max(gans, csum);
    }
    return gans;
}

int solve(vector<int>& v, int n, int k, int sum) {

    if (k == 1) {
        return kadane(v, n);
    }
    else if (sum < 0) {
        vector<int>temp = v;
        temp.insert(temp.end(), v.begin(), v.end());

        return kadane(temp, 2 * n);
    }
    else {

        int ans = 0;
        vector<int>temp = v;
        temp.insert(temp.end(), v.begin(), v.end());

        ans = kadane(temp, 2 * n);
        ans += (k - 2) * sum;

        return ans;
    }
}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int k;
    cin >> k;

    cout << solve(v, n, k, sum);

    return 0;
}