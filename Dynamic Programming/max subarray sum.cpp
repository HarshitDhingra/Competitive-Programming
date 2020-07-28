#include <iostream>
using namespace std;

int maxsum(int a[], int n)
{
    int dp[1000];

    dp[0] = a[0] > 0 ? a[0] : 0;
    int max_so_far = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0) {
            dp[i] = 0;
        }
        if (max_so_far < dp[i]) {
            max_so_far = dp[i];
        }
    }
    return max_so_far;
}

int kadane(int a[], int n)
{
    int currentsum = -100;
    int globalsum = -100;

    for (int i = 0; i < n; i++)
    {
        currentsum = max(currentsum + a[i], a[i]);
        globalsum = max(globalsum, currentsum);
    }
    return globalsum;
}

int main() {
    int a[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(a) / sizeof(int);
    cout << maxsum(a, n) << endl;
    cout << kadane(a, n);
}
