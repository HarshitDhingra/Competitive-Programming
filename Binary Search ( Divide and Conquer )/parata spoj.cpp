#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int p, int mintime)
{
    int ans = 0, sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        sum = 0;
        while (sum + temp <= mintime)
        {
            sum = sum + temp;
            count++;
            temp = temp + a[i];
        }
        ans += count;
    }
    if (count < p)
        return false;

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int p, n;
        cin >> p >> n;
        int a[1001];
        int lowestrank = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            lowestrank = min(lowestrank, a[i]);
        }
        int temp = (1000 * 1001) / 2;

        int s = 0;
        int e = lowestrank * temp;
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (isPossible(a, n, p, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        cout << ans << endl;
    }
}
