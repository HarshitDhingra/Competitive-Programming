#include <iostream>
using namespace std;

int dp[100][100];

int optimalgame_top_down(int a[], int i, int j)
{
    if (i > j) {
        return 0;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }

    int ans1 = a[i] + min(optimalgame_top_down(a, i + 2, j), optimalgame_top_down(a, i + 1, j - 1));
    int ans2 = a[j] + min(optimalgame_top_down(a, i, j - 2), optimalgame_top_down(a, i + 1, j - 1));
    int ans = max(ans1, ans2);

    dp[i][j] = ans;

    return ans;
}

int optimalgame_bottm_up(int a[], int n)
{
    int dp[100][100];

    for (int diag = 0; diag < n; diag++)
    {
        int i = 0;
        int j = diag;
        while (j < n)
        {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                int ans1 = a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int ans2 = a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(ans1, ans2);
            }
            i++; j++;
        }
    }

    return dp[0][n - 1];
}

int main() {
    int a[] = {8, 15, 3, 7};
    int n = sizeof(a) / sizeof(int);
    cout << optimalgame_top_down(a, 0, n - 1) << endl;
    cout << optimalgame_bottm_up(a, n);
}
