#include <iostream>
using namespace std;

int dp[100][100];

int wines_top_down(int wines[], int i, int j, int year)
{
    if (i > j) {
        return 0;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }

    int ans1 = 0, ans2 = 0;
    ans1 = (wines[i] * year) + wines_top_down(wines, i + 1, j, year + 1);
    ans2 = (wines[j] * year) + wines_top_down(wines, i, j - 1, year + 1);

    int ans = max(ans1, ans2);
    dp[i][j] = ans;

    return  ans;
}

int wines_bottom_up(int wines[], int n)
{
    int dp[100][100];

    for (int diagonal = 0; diagonal < n; diagonal++)
    {
        int i = 0;
        int j = diagonal;
        while (j < n)
        {
            if (i == j)
            {
                dp[i][j] = wines[i] * (n - diagonal);
            }
            else {
                int ans1 = 0, ans2 = 0;
                ans1 = wines[i] * (n - diagonal) + dp[i + 1][j];
                ans2 = wines[j] * (n - diagonal) + dp[i][j - 1];
                dp[i][j] = max(ans1, ans2);
            }
            i++; j++;
        }
    }
    return dp[0][n - 1];
}

int main() {
    int wines[] = {2, 3, 5, 1, 4};
    cout << wines_top_down(wines, 0, 4, 1) << endl;
    cout << wines_bottom_up(wines, 5) << endl;
}
