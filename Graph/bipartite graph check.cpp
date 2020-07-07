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

    bool bipartite_checker(int node, bool visited[], bool color[], int col)
    {
        if (visited[node])
        {
            return color[node] == col;
        }

        color[node] = col;
        visited[node] = true;

        for (int nbr : l[node])
        {
            bool isbipartite = bipartite_checker(nbr, visited, color, 1 - col);
            if (isbipartite == false)
                return false;
        }
        return true;
    }

    bool bipartite()
    {
        bool* visited = new bool[V] {0};
        bool* color = new bool[V] {0};

        // for(int i=0;i<V;i++)
        // {
        //     visited[i]=false;
        //     color[i]=0;
        // }

        return bipartite_checker(0, visited, color, 0);
    }

};

int main() {
    graph g;
    V = 6;

    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 5);
    g.addedge(5, 0);

    if (g.bipartite())
        cout << "Bipartite graph";
    else cout << "Not a bipartite graph";

}
