#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& keys, vector<int>& freq, int n) {


    int dp[n][n] = {0};
    //memset(dp,0,sizeof(dp));

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {
                dp[i][j] = freq[i];
            }
            else if (d == 1) {
                dp[i][j] = min(freq[i] + 2 * freq[j], 2 * freq[i] + freq[j]);
            }
            else {
                dp[i][j] = INT_MAX;

                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += freq[k];
                }

                for (int k = i; k <= j; k++) {

                    int x = (k - 1 >= 0) ? dp[i][k - 1] : 0;
                    int y = (k + 1 <= j) ? dp[k + 1][j] : 0;

                    dp[i][j] = min(dp[i][j], x + y + sum);

                }

            }

            i++; j++;
        }

    }

    return dp[0][n - 1];
}

int solve1(vector<int>& keys, vector<int>& freq, int n) {

    int dp[n][n] = {0};

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {
                dp[i][j] = freq[i];
            }
            else if (d == 1) {
                dp[i][j] = min(freq[i] + 2 * freq[j], 2 * freq[i] + freq[j]);
            }
            else {

                int sum = 0;
                int temp = INT_MAX;

                for (int k = i; k <= j; k++) {

                    int x = (k - 1 >= 0) ? dp[i][k - 1] : 0;
                    int y = (k + 1 <= j) ? dp[k + 1][j] : 0;

                    sum += freq[k];

                    temp = min(temp, x + y);
                }
                dp[i][j] = temp + sum;

            }

            i++; j++;
        }

    }

    return dp[0][n - 1];
}

int main() {

    int n;
    cin >> n;

    vector<int>keys(n);
    vector<int>freq(n);

    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    cout << solve1(keys, freq, n);

    return 0;
}