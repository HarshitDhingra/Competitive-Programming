#include <bits/stdc++.h>
using namespace std;

const int N = 10001, M = 22;
vector<int>graph[N];
int depth[N];
int par[N][M];

void dfs(int src, int parent)
{
    for (auto child : graph[src])
    {
        if (child != parent)
        {
            depth[child] = depth[src] + 1;
            dfs(child, src);
        }
    }
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

int lca(int u, int v)
{
    if (u == v)
        return u;

    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];

    for (int i = M - 1; i >= 0; i--)
    {
        if ( (diff >> i) & 1 )
        {
            u = par[u][i];
        }
    }

    for (int i = M - 1; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
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
    dfs(1, 0);
    sparse_table(1, 0);
    cout << lca(18, 16);
}

// input ->
// 19
// 1 2
// 2 4
// 2 5
// 5 6
// 6 7
// 6 8
// 6 9
// 1 3
// 3 10
// 3 11
// 10 17
// 17 18
// 17 19
// 11 12
// 12 13
// 12 14
// 12 15
// 15 16