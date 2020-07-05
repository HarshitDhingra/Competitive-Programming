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
        map<int, int>dist;
        queue<int>q;

        for (auto i : l)
        {
            int node = i.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            //cout<<node<<" ";
            for (int nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        for (auto i : l)
        {
            int node = i.first;
            cout << node << " -> " << dist[node] << endl;
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
