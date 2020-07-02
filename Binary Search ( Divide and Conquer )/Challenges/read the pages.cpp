#include <bits/stdc++.h>
using namespace std;

bool canplace(long long a[], long long n, long long m, long long max)
{
    long long count = 1, sum = 0;
    for (long long i = 0; i < n; i++)
    {
        if (sum + a[i] > max)
        {
            count++;
            sum = a[i];
            if (count > m)
                return false;
        }
        else {
            sum += a[i];
        }
    }
    return true;
}

long long findpages(long long a[], long long n, long long m)
{
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
    }

    long long s = a[n - 1];
    long long e = sum;
    long long ans = INT_MAX;

    while (s <= e)
    {
        long long mid = (s + e) / 2;

        if (canplace(a, n, m, mid))
        {
            //ans = mid;
            ans = min(ans, mid);
            e = mid - 1;
            //cout<<ans<<endl;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {

    long long n, m;
    cin >> n >> m;
    long long a[1000001];
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    cout << findpages(a, n, m) << endl;

}
