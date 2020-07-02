#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int p, int mintime)
{
    int ans = 0, sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        while (a[i]*count * (count + 1) <= mintime * 2)
        {
            count++;
        }
        count--;
        ans += count;
    }
    if (ans < p)
        return false;

    return true;
}

int main() {
    int t = 1;
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
