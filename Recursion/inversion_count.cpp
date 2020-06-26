#include <iostream>
using namespace std;

int merge(int a[], int s, int e)
{
    int temp[1000], mid = (s + e) / 2;
    int i = s; int j = mid + 1, k = s;
    int ans = 0;
    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
    return ans;
}

int inversion_count(int a[], int s, int e)
{
    if (s >= e)
        return 0;

    int mid = (s + e) / 2;
    int x = inversion_count(a, s, mid);
    int y = inversion_count(a, mid + 1, e);
    int z = merge(a, s, e);

    return x + y + z;
}

int main() {
    int a[] = {1, 5, 2, 6, 3, 0};
    int n = 6;
    cout << inversion_count(a, 0, n - 1);
    // for(int i=0;i<n;i++)
    // cout<<a[i]<<" ";
}
