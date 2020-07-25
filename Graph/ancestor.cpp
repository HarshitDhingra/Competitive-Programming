#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int>graph[N];
int visited[N];
int tin[N], tout[N];
int timer = 0;

void euler_tour_3(int src, int parent)
{
    // cout<<src<<" ";
    tin[src] = ++timer;

    for (auto i : graph[src])
    {
        if (i != parent)
        {
            euler_tour_3(i, src);
        }
    }
    tout[src] = timer;
}

bool isancestor(int x, int y)
{
    if (tin[x] <= tin[y] && tout[x] >= tout[y])
        return true;

    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    euler_tour_3(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> " << tin[i] << " " << tout[i] << endl;
    }
    if (isancestor(3, 8))
        cout << "yes\n";
    else cout << "no\n";

}
