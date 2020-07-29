#include <bits/stdc++.h>
using namespace std;

int cell_top_down(int n, int x, int y, int z)
{
    if (n == 1) {
        return 0;
    }

    int ans = INT_MAX;
    if (n % 2 == 0)
    {
        ans = min(x + cell_top_down(n / 2, x, y, z), y + cell_top_down(n - 1, x, y, z));
    }
    else
    {
        ans = min(y + cell_top_down(n - 1, x, y, z), x + z + cell_top_down((n + 1) / 2, x, y, z));
    }

    return ans;
}

int cell_bottom_up(int n, int x, int y, int z)
{
    int dp[100];
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0) {
            dp[i] = min(x + dp[i / 2], y + dp[i - 1]);
        }
        else {
            dp[i] = min(y + dp[i - 1], x + z + dp[(i + 1) / 2]);
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    cout << cell_top_down(n, x, y, z) << endl;
    cout << cell_bottom_up(n, x, y, z);

}
