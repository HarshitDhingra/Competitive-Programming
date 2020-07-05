#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int, list<int>>l;

public:
    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    int dfs_helper(int src, map<int, bool>& visited)
    {
        int ans = 1;
        visited[src] = true;

        for (int nbr : l[src])
        {
            if (!visited[nbr])
            {
                ans += dfs_helper(nbr, visited);
            }
        }
        return ans;

    }

    int dfs(int n)
    {
        int ans = 0;
        map<int, bool>visited;
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int temp = dfs_helper(i, visited);
                //cout<<temp<<" ";
                ans += (temp * (temp - 1)) / 2;
            }
        }
        return ans;
    }

};

int main() {

    graph g;
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addedge(x, y);
    }
    int total = (n * (n - 1)) / 2;
    int ans = total - g.dfs(n);

    cout << ans;
}
