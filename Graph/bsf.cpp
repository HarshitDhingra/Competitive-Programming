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

    void bfs(int src)
    {
        map<int, bool>visited;
        queue<int>q;

        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visited[node] = true;
            cout << node << " ";
            for (int nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
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

    g.bfs(0);

}
