#include <iostream>
using namespace std;

int solve(int a[], int n)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (a[mid] > a[mid + 1])
        {
            ans = mid;
            return mid;
        }
        else if (a[mid] < a[s])
        {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[100001];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(a, n);
}
