#include <bits/stdc++.h>
using namespace std;

const int N = 10001, M = 22;
vector<int>graph[N];
int par[N][M];
int tin[N], tout[N];
int timer;

void dfs(int src, int parent)
{
    tin[src] = ++timer;

    for (auto child : graph[src])
    {
        if (child != parent)
        {
            dfs(child, src);
        }
    }
    tout[src] = timer;
}

void sparse_table(int src, int parent)
{
    par[src][0] = parent;

    for (int j = 1; j < M; j++)
    {
        par[src][j] = par[par[src][j - 1]][j - 1];
    }

    for (auto child : graph[src])
    {
        if (child != parent)
        {
            sparse_table(child, src);
        }
    }
}

bool is_ancestor(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v)
{
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = M - 1; i >= 0; i--)
    {
        if (!is_ancestor(par[u][i], v))
        {
            u = par[u][i];
        }
    }
    return par[u][0];
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
    timer = 0;
    tin[0] = 0; tout[0] = n + 1;
    dfs(1, 0);
    sparse_table(1, 0);
    cout << lca(11, 16);
}