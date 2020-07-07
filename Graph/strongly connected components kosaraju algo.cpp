#include <bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int>graph[N];
vector<int>revgraph[N];
vector<int>ordering;
int visited[N], components[N];

void dfs(int src)
{
    visited[src] = 1;

    for (auto nbr : graph[src])
    {
        if (!visited[nbr])
            dfs(nbr);
    }
    ordering.push_back(src);
}

void revdfs(int src, int color)
{
    visited[src] = 1;
    components[src] = color;

    for (int nbr : revgraph[src])
    {
        if (!visited[nbr])
            revdfs(nbr, color);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        revgraph[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    // for(int i:ordering)
    // cout<<i<<" ";

    memset(visited, 0, sizeof(visited));

    int color = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (!visited[ordering[i]])
        {
            revdfs(ordering[i], color);
            color++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "->" << components[i] << endl;
    }
}

// input for graph
// 6 7
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5
// 5 6
// 6 4