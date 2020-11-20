#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int primes[MAX + 1];
int nextprime[MAX + 1];
int prevprime[MAX + 1];

int cost(int x, int y)
{
    int sub = x + y;
    int a = x, b = y;
    if (x <= y && prevprime[y - 1] >= x)
        return nextprime[y] + prevprime[y - 1] - x - y;

    x = max(x, y);
    x = nextprime[x];
    y = nextprime[x + 1];

    return x + y - sub;
}

int solve1(int a[], int n) {

    int dp[n + 5][n + 5] = {0};
    memset(dp, 0, sizeof dp);

    for (int d = 1; d < n; d += 2) {
        int i = 0;
        int j = d;

        while (j < n) {
            dp[i][j] = INT_MAX;
            if (d == 1) {
                dp[i][j] = cost(a[i], a[j]);
            }
            else {
                for (int k = i + 1; k < j; k += 2) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                int temp = dp[i + 1][j - 1] + cost(a[i], a[j]);
                dp[i][j] = min(dp[i][j], temp);
            }
            i++; j++;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << (dp[0][n - 1] + n / 2);

    return dp[0][n - 1];
}

int solve2(int a[], int n) {

    int dp[n + 5][n + 5] = {0};
    memset(dp, 0, sizeof dp);

    for (int d = 1; d < n; d += 2) {
        int i = 0;
        int j = d;

        while (j < n) {
            dp[i][j] = INT_MAX;
            if (d == 1) {
                dp[i][j] = cost(a[i], a[j]);
            }
            else {
                for (int k = i; k < j; k += 2) {

                    int p = 0, q = 0;
                    if (k - 1 <= i) {
                        p = 0;
                    }
                    else {
                        p = dp[i][k - 1];
                    }
                    if (k + 1 <= j - 1) {
                        q = dp[k + 1][j - 1];
                    }
                    else {
                        q = 0;
                    }
                    int temp = p + q + cost(a[k], a[j]);

                    dp[i][j] = min(dp[i][j], temp);
                }
            }
            i++; j++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << (dp[0][n - 1] + n / 2);

    return dp[0][n - 1];
}

int main() {

    primes[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (primes[i])
            continue;
        for (int j = 2 * i; j <= MAX; j += i) {
            primes[j] = 1;
        }
    }

    for (int i = MAX - 1; i >= 0; i--) {
        if (primes[i] == 0) {
            nextprime[i] = i;
        }
        else {
            nextprime[i] = nextprime[i + 1];
        }
    }


    for (int i = 1; i < MAX; i++) {
        if (primes[i] == 0) {
            prevprime[i] = i;
        }
        else {
            prevprime[i] = prevprime[i - 1];
        }
    }


    int a[] = {1, 2, 4, 3, 6, 5, 27, 12, 13, 15, 19, 20};
    int n = sizeof(a) / sizeof(int);

    solve1(a, n);
    cout << endl;
    solve2(a, n);

    return 0;
}
