#include <bits/stdc++.h>
using namespace std;

long long solve2(int n) {
    vector<long long>dp0(n + 1, 0);
    vector<long long>dp1(n + 1, 0);
    dp0[1] = 1;
    dp1[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp0[i] = dp1[i - 1];
        dp1[i] = dp1[i - 1] + dp0[i - 1];
    }
    return dp0[n] + dp1[n];
}

int main() {

    int n;
    cin >> n;
    long long ans = solve2(n);
    ans = ans * ans;
    cout << ans;

    return 0;
}