#include <bits/stdc++.h>
using namespace std;

const int n = 50;
vector<int>graph[n];

void bfs(int src, int n, int &ans)
{
    vector<int>dist(n + 1, INT_MAX);
    queue<int>q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int nbr : graph[node])
        {
            if (dist[nbr] == INT_MAX)
            {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
            else if (dist[nbr] >= dist[node])
            {
                ans = min(ans, dist[nbr] + dist[node] + 1);
            }
        }
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
        graph[y].push_back(x);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        bfs(i, n, ans);
    }
    if (ans == INT_MAX)
        cout << "Doesn't contain a cycle";
    else cout << "min length of cycle is " << ans;

}
