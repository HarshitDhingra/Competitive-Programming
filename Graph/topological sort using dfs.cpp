#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int, list<int>>l;

public:
    void addedge(int x, int y)
    {
        l[x].push_back(y);
    }

    void dfs_helper(int src, map<int, bool>& visited, list<int>& ordering)
    {
        visited[src] = true;

        for (int nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited, ordering);
            }
        }

        ordering.push_front(src);
        return ;
    }

    void dfs(int src)
    {
        map<int, bool>visited;
        list<int>ordering;
        for (auto i : l)
        {
            int node = i.first;
            visited[node] = false;
        }

        for (auto i : l)
        {
            int node = i.first;
            if (!visited[node])
                dfs_helper(node, visited, ordering);

        }

        for (int i : ordering)
            cout << i << " ";

    }

};

int main() {
    graph g;

    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(2, 1);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 5);

    g.dfs(0);

}
