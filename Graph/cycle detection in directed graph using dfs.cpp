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

    bool cycle_helper(int node, bool visited[], bool stack[])
    {
        visited[node] = true;
        stack[node] = true;

        for (int nbr : l[node])
        {
            if (stack[nbr] == true)
                return true;
            else if (!visited[nbr])
            {
                bool iscycle = cycle_helper(nbr, visited, stack);
                if (iscycle)
                    return true;
            }
        }
        stack[node] = false;
        return false;
    }

    bool contains_cycle()
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = stack[i] = false;

        return cycle_helper(0, visited, stack);

    }

};

int main() {
    graph g;
    V = 6;

    g.addedge(0, 1);
    g.addedge(3, 0);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 5);

    if (g.contains_cycle())
        cout << "Contains a cycle";
    else cout << "doesn't contain a cycle";
}
