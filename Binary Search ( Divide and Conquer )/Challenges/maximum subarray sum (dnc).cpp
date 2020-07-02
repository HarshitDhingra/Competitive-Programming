#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int s, int e)
{
    if (s == e)
        return a[s];
    if (s > e)
        return INT_MIN;

    int mid = (s + e) / 2;
    int left = solve(a, n, s, mid);
    int right = solve(a, n, mid + 1, e);

    int maxsuf = INT_MIN;
    int maxpref = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= s; i--)
    {
        sum += a[i];
        maxpref = max(maxpref, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= e; i++)
    {
        sum += a[i];
        maxsuf = max(maxsuf, sum);
    }
    // cout<<maxpref<<" "<<maxsuf<<endl;
    int ans = max( (maxpref + maxsuf) , max(left, right) );
    // cout<<ans<<" ";

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[100001];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << solve(a, n, 0, n - 1) << endl;
    }
}
