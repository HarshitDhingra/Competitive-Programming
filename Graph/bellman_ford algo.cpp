#include <bits/stdc++.h>
using namespace std;

vector<int>bellman_ford(int src, int n, vector<vector<int>>&edges)
{
    vector<int>dist(n + 1, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if ( dist[u] != INT_MAX && dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if ( dist[u] + w < dist[v] )
        {
            cout << "Negative weight cycle detected";
            return {};
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    vector<int>ans = bellman_ford(1, n, edges);

    for (int i = 1; i < ans.size(); i++)
    {
        cout << i << "-> " << ans[i] << endl;
    }

}
