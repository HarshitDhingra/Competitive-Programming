#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int k, int mid)
{
    int count = 1;
    int sum = a[0];

    for (int i = 1; i < n; i++)
    {
        if (sum + a[i] > mid)
        {
            count++;
            sum = a[i];
        }
        else {
            sum += a[i];
        }
    }
    if (count <= k)
        return true;

    return false;

}

int main() {
    int k, n;
    cin >> k >> n;
    int a[100001];
    int sum = 0;
    int maxele = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        maxele = max(maxele, a[i]);
    }

    int s = maxele;
    int e = sum;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (isPossible(a, n, k, mid))
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
