#include <bits/stdc++.h>
using namespace std;

bool isSafe(int mat[9][9], int i, int j, int n, int number)
{
    for (int x = 0; x < n; x++)
    {
        if (mat[i][x] == number || mat[x][j] == number)
            return false;
    }
    int rn = sqrt(n);
    int startx = (i / rn) * rn;
    int starty = (j / rn) * rn;

    for (int x = startx; x < startx + rn; x++)
    {
        for (int y = starty; y < starty + rn; y++)
        {
            if (mat[x][y] == number)
                return false;
        }
    }
    return true;
}

bool sodokuSolver(int mat[9][9], int i, int j, int n)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }
    if (j == n)
    {
        return sodokuSolver(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
        return sodokuSolver(mat, i, j + 1, n);
    }

    for (int k = 1; k <= n; k++)
    {
        if (isSafe(mat, i, j, n, k))
        {
            mat[i][j] = k;
            bool subans = sodokuSolver(mat, i, j + 1, n);
            if (subans == true)
                return true;
        }
    }
    mat[i][j] = 0;
    return false;
}

int main() {

    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sodokuSolver(mat, 0, 0, 9);
}
