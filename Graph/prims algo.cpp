#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, int>>graph[n + 1];
    bool visited[n + 1] = {0};

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({w, y});
        graph[y].push_back({w, x});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    q.push({0, 1});

    while (!q.empty())
    {
        pair<int, int>edge = q.top();
        q.pop();

        int node = edge.second;
        int weight = edge.first;

        if (visited[node])
            continue;

        visited[node] = true;
        ans += weight;

        for (auto nbr : graph[node])
        {
            int nbrnode = nbr.second;
            int nbrwt = nbr.first;
            if (!visited[nbrnode])
            {
                q.push({nbrwt, nbrnode});
            }
        }
    }
    cout << ans << endl;
}
