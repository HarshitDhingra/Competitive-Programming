#include <bits/stdc++.h>
using namespace std;

int parent[10000];

int getparent(int x)
{
    if (x = parent[x])
        return x;

    return parent[x] = getparent(parent[x]);
}

void unite(int x, int y)
{
    int a = getparent(x);
    int b = getparent(y);
    if (a != b)
    {
        parent[a] = b;
    }
}

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<vector<int>>edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = {w, x, y};
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i <= n + 1; i++)
        parent[i] = i;

    for (int i = 1; i <= n - 1; i++)
    {
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];
        if (getparent(x) != getparent(y))
        {
            unite(x, y);
            sum += w;
        }
    }
    cout << sum << endl;
}
