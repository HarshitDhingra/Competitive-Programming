#include <bits/stdc++.h>
using namespace std;

int solve1(int v[][11], int n, int k) {

    int dp[1001][11];

    int least = INT_MAX;
    int sleast = INT_MAX;

    for (int j = 0; j < k; j++) {
        dp[0][j] = v[0][j];

        if (dp[0][j] <= least) {
            sleast = least;
            least = dp[0][j];
        }
        else if (dp[0][j] <= sleast) {
            sleast = dp[0][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        int nleast, nsleast;
        nleast = nsleast = INT_MAX;

        for (int j = 0; j < k; j++)
        {
            if (dp[i - 1][j] != least) {
                dp[i][j] = v[i][j] + least;
            }
            else {
                dp[i][j] = v[i][j] + sleast;
            }

            if (dp[i][j] <= nleast) {
                nsleast = nleast;
                nleast = dp[i][j];
            }
            else if (dp[i][j] <= nsleast) {
                nsleast = dp[i][j];
            }

        }
        least = nleast;
        sleast = nsleast;
    }

    return least;
}

int main() {

    int n, k;
    cin >> n >> k;
    int v[1001][11];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> v[i][j];
        }
    }
    cout << solve1(v, n, k);

    return 0;
}