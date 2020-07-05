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

    void dfs_helper(int src, map<int, bool>& visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (int nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }

    }

    void dfs(int src)
    {
        map<int, bool>visited;
        for (auto i : l)
        {
            int node = i.first;
            visited[node] = false;
        }
        dfs_helper(src, visited);
    }

};

int main() {
    graph g;

    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 5);

    g.dfs(0);

}
