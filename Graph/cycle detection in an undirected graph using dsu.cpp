#include <iostream>
using namespace std;

int const N = 100;
int parent[N];

int superparent(int x)
{
    if (x == parent[x])
        return x;

    else return parent[x] = superparent(parent[x]);
}

void unite(int x, int y)
{
    int a = superparent(x);
    int b = superparent(y);
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    int n, m, ans = 0;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    int flag = 0;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        if (superparent(x) != superparent(y))
            unite(x, y);
        else flag = 1;
    }

    if (flag)
        cout << "cycle detected\n";
    else cout << "no cycle detected\n";


}
