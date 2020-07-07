#include <bits/stdc++.h>
using namespace std;

int V;

class graph
{
    map<int, list<int>>l;

public:
    void addedge(int x, int y)
    {
        l[x].push_back(y);
    }

    void topological_sort()
    {
        int* indegree = new int[V];

        for (int i = 0; i < V; i++)
            indegree[i] = 0;

        for (int i = 0; i < V; i++)
        {
            for (auto j : l[i])
                indegree[j]++;
        }

        queue<int>q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (int nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }

};

int main() {
    graph g;
    V = 6;

    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(2, 1);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 5);

    g.topological_sort();

}
