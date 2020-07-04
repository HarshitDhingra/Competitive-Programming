#include <iostream>
#define mod 1000000007
using namespace std;

long long ans = 0;

void merge(int a[], int n, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    int i = s, j = mid + 1, k = s;
    int temp[100001];

    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            ans = (ans % mod + a[i] * (e - j + 1) % mod) % mod;
            k++; i++;
        }
        else {
            temp[k] = a[j];
            k++; j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++; i++;
    }
    while (j <= e)
    {
        temp[k] = a[j];
        k++; j++;
    }
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

void solve(int a[], int n, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    solve(a, n, s, mid);
    solve(a, n, mid + 1, e);
    merge(a, n, s, e);

}

int main() {
    int n;
    cin >> n;
    int a[1000001];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    solve(a, n, 0, n - 1);
    cout << ans;
}
