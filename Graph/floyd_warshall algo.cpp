#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd_warshall(int n, vector<vector<int>>&edges)
{
    vector<vector<int>>dist(n + 1, vector<int>(n + 1, 1e9));

    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
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

    vector<vector<int>>ans = floyd_warshall(n, edges);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j] < 1e8)
                cout << ans[i][j] << " ";
            else cout << "inf ";
        }
        cout << endl;
    }

}
