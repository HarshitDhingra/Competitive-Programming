#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int>graph[N];
set<int>art_points;
set<pair<int, int>>bridges;
int discovered[N], lowest[N];
int timer;

void dfs(int src, int parent)
{
    discovered[src] = lowest[src] = timer++;
    int no_child = 0;

    for (auto child : graph[src])
    {
        if (discovered[child] == 0)
        {
            no_child++;
            dfs(child, src);
            lowest[src] = min(lowest[src], lowest[child]);

            if (parent != 0 && lowest[child] >= discovered[src])
            {
                art_points.insert(src);
            }
            if (lowest[child] > discovered[src])
            {
                bridges.insert({src, child});
            }
        }
        else if (child != parent)
        {
            lowest[src] = min(lowest[src], discovered[child]);
        }
    }
    if (parent == 0 && no_child >= 2)
    {
        art_points.insert(src);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    timer = 1;
    dfs(1, 0);
    cout << "Articulation points -> \n";
    for (auto i : art_points)
        cout << i << " ";

    cout << endl;

    cout << "Bridges -> \n";
    for (auto i : bridges)
        cout << i.first << " " << i.second << endl;


}
