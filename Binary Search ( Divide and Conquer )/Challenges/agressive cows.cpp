#include <bits/stdc++.h>
using namespace std;

bool canPlace(long long stalls[], long long n, long long cows, long long minlen)
{
    long long laststall = stalls[0];
    long long count = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - laststall >= minlen)
        {
            laststall = stalls[i];
            count++;
            if (count == cows)
                return true;
        }
    }

    return false;
}

int main() {

    long long n, cows, stalls[100001];
    cin >> n >> cows;
    for (int i = 0; i < n; i++)
        cin >> stalls[i];

    sort(stalls, stalls + n);

    long long s = 0;
    long long e = stalls[n - 1] - stalls[0];
    long long ans = -1;

    while (s <= e)
    {
        long long mid = (s + e) / 2;

        if (canPlace(stalls, n, cows, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    cout << ans << endl;
}
