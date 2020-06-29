#include <iostream>
using namespace std;

char maze[1001][1001];
int soln[1001][1001] = {0};

bool rec(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        soln[i][j] = 1;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                cout << soln[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    if (maze[i][j] == 'X')
        return false;

    soln[i][j] = 1;

    int right = rec(i, j + 1, n, m);
    if (right)
        return true;

    int down = rec(i + 1, j, n, m);
    if (down)
        return true;

    soln[i][j] = 0;

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    if (!rec(0, 0, n, m))
        cout << "-1";
}
