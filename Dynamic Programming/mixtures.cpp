#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int sum(int a[], int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += a[k];
        sum = sum % 100;
    }
    return sum;
}

int  mixtures(int a[], int i, int j)
{
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int subans = mixtures(a, i, k) + mixtures(a, k + 1, j) + (sum(a, i, k) * sum(a, k + 1, j));
        ans = min(ans, subans);
    }

    dp[i][j] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        cout << mixtures(a, 0, n - 1) << endl;
    }
}
