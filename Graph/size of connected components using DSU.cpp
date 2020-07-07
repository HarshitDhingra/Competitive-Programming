#include <iostream>
using namespace std;

int const N = 100;
int parent[N];
int size[N];
int totalcomponents;

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
        size[b] = size[b] + size[a];
        size[a] = 0;
        totalcomponents--;
    }
}

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    totalcomponents = n;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    for (int i = 0; i < n; i++)
    {
        int getsuperparent = superparent(i);
        ans += n - size[getsuperparent];
    }
    cout << ans << endl;

}
