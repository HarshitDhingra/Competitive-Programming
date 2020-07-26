#include <bits/stdc++.h>
using namespace std;

const int N = 10001;
vector<int>graph[N];
int depth[N], par[N];

void dfs(int src, int parent)
{
    par[src] = parent;
    for (auto child : graph[src])
    {
        if (child != parent)
        {
            depth[child] = depth[src] + 1;
            dfs(child, src);
        }
    }
}

int lca_brute(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    while (depth[u] > depth[v])
    {
        u = par[u];
    }

    while (u != v)
    {
        u = par[u];
        v = par[v];
    }
    return u;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0);
    cout << lca_brute(7, 16);
}
