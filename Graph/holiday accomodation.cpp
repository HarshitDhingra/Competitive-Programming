#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int, list<pair<int, int>>>l;

public:
    void addedge(int x, int y, int cost)
    {
        l[x].push_back({y, cost});
        l[y].push_back({x, cost});
    }

    int dfs_helper(int node, bool visited[], int count[], int &ans, int V)
    {
        count[node] = 1;
        visited[node] = true;

        for (auto i : l[node])
        {
            int nbr = i.first;
            int wt = i.second;
            if (!visited[nbr])
            {
                count[node] += dfs_helper(nbr, visited, count, ans, V);
                int nx = count[nbr];
                int ny = V - nx;
                ans += 2 * min(nx, ny) * wt;
            }
        }

        return count[node];
    }

    int dfs(int V)
    {
        bool* visited = new bool[V];
        int* count = new int[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            count[i] = 0;
        }

        int ans = 0;

        dfs_helper(1, visited, count, ans, V);

        return ans;
    }

};

int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        graph g;
        for (int i = 1; i <= n - 1; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g.addedge(x, y, z);
        }
        cout << g.dfs(n) << endl;

    }

}
