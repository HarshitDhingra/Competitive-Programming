#include <iostream>
using namespace std;

bool canplace(int a[], int n, int m, int max)
{
    int count = 1, sum = 0;
    for (int i = 0; i < n; i++)
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

int findpages(int a[], int n, int m)
{
    if (n < m)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    int s = a[n - 1];
    int e = sum;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (canplace(a, n, m, mid))
        {
            ans = mid;
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[10000];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << findpages(a, n, m) << endl;
    }
}
