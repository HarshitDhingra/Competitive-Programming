#include <bits/stdc++.h>
using namespace std;

int query(int blocks[], int a[], int l, int r, int rn)
{
    int ans = 0;

    while (l < r && l % r != 0)
    {
        ans += a[l];
        l++;
    }

    while (l + rn < r)
    {
        int index = l / rn;
        ans += blocks[index];
        l += rn;
    }

    while (l <= r)
    {
        ans += a[l];
        l++;
    }

    return ans;
}

void update(int blocks[], int a[], int i, int val, int rn)
{
    int index = i / rn;
    blocks[index] += val - a[i];
    a[i] = val;
}

int main() {

    int a[] = {1, 3, 5, 2, 7, 6, 3, 1, 4, 8};
    int n = sizeof(a) / sizeof(int);

    int rn = sqrt(n);

    int blocks[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        int index = i / rn;
        blocks[index] += a[i];
    }

    int l, r;
    cin >> l >> r;
    update(blocks, a, 2, 15, rn);
    cout << query(blocks, a, l, r, rn);

}
