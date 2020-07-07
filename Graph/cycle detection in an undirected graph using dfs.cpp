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
        l[y].push_back(x);
    }

    bool cycle_helper(int node, bool visited[], int parent)
    {
        visited[node] = true;

        for (int nbr : l[node])
        {
            if (!visited[nbr]) {
                bool iscycle = cycle_helper(nbr, visited, node);
                if (iscycle)
                    return true;

            }
            else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle()
    {

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        return cycle_helper(0, visited, -1);
    }

};

int main() {
    graph g;
    V = 5;

    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 0);

    if (g.contains_cycle())
        cout << "Contains a cycle";
    else cout << "Doesn't contain a cycle";

}
