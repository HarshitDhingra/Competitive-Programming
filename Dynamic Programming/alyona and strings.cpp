#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][11][2];
int n, m, k;
string s, t;

int rec(int is, int it, int rem, int cont)
{
    if (is == n || it == m) {
        return ((rem == 0) ? 0 : INT_MIN);
    }
    if (rem == 0) {
        return 0;
    }
    if (dp[is][it][rem][cont] != -1) {
        return dp[is][it][rem][cont];
    }

    int ans = INT_MIN;
    if (cont == 1) {
        ans = max(ans, rec(is + 1, it, rem - 1, 0));
        ans = max(ans, rec(is, it + 1, rem - 1, 0));
        if (s[is] == t[it]) {
            ans = max(ans, 1 + rec(is + 1, it + 1, rem, 1));
            ans = max(ans, 1 + rec(is + 1, it + 1, rem - 1, 0));
        }
    }
    else {
        ans = max(ans, rec(is + 1, it, rem, 0));
        ans = max(ans, rec(is, it + 1, rem, 0));
        if (s[is] == t[it]) {
            ans = max(ans, 1 + rec(is + 1, it + 1, rem, 1));
            ans = max(ans, 1 + rec(is + 1, it + 1, rem - 1, 0));
        }
    }
    dp[is][it][rem][cont] = ans;

    return ans;
}

int main() {
    cin >> n >> m >> k;
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, k, 0);


}
