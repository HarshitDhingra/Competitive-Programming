#include <bits/stdc++.h>
using namespace std;

int parent[100000];

int getparent(int x)
{
    if (x == parent[x])
        return x;

    else return parent[x] = getparent(parent[x]);
}

void unite(int x, int y)
{
    int a = getparent(x);
    int b = getparent(y);
    if (a != b)
    {
        parent[a] = max(parent[a], parent[b]);
        parent[b] = max(parent[a], parent[b]);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    int l[q], r[q], c[q];
    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i] >> c[i];
    }

    for (int i = 0; i < n + 2; i++)
    {
        parent[i] = i;
    }
    vector<int>ans(n + 2);

    for (int i = q - 1; i >= 0; i--)
    {
        int index = getparent(l[i]);

        while (index <= r[i])
        {
            ans[index] = c[i];
            unite(index, index + 1);
            index = getparent(index);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

}
