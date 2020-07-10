#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<pair<int, int>>>m;
public:
    void addedge(int x, int y, int w, bool bidir = true)
    {
        m[x].push_back({y, w});
        if (bidir)
            m[y].push_back({x, w});
    }
    void dijkstras(int src)
    {
        map<int, int >dist;

        for (auto i : m)
        {
            dist[i.first] = INT_MAX;
        }

        set<pair<int, int>>s;
        dist[src] = 0;
        s.insert({dist[src], src});

        while (!s.empty())
        {
            auto i = *s.begin();
            s.erase(s.begin());
            int node = i.second;
            int nodedist = i.first;

            for (auto nbr : m[node])
            {
                if (nodedist + nbr.second < dist[nbr.first])
                {
                    int nbrnode = nbr.first;
                    auto temp = s.find({dist[nbrnode], nbrnode});
                    if (temp != s.end())
                    {
                        s.erase(temp);
                    }

                    dist[nbrnode] = dist[node] + nbr.second;
                    s.insert({dist[nbrnode], nbrnode});
                }
            }
        }
        for (auto i : dist) {
            cout << i.first << " -> " << i.second << endl;
        }
    }
};

int main() {

    Graph g ;
    g.addedge(1, 2, 1);
    g.addedge(1, 3, 4);
    g.addedge(2, 3, 1);
    g.addedge(3, 4, 2);
    g.addedge(1, 4, 7);
    g.dijkstras(1);

}
