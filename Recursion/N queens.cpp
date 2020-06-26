#include <iostream>
using namespace std;

bool isSafe(int soln[10][10], int i, int j, int n)
{
    for (int row = 0; row < i; row++)
    {
        if (soln[row][j] == 1)
            return false;
    }

    int row = i, col = j;

    while (row >= 0 && col >= 0)
    {
        if (soln[row][col] == 1)
            return false;
        row--;
        col--;
    }
    row = i;
    col = j;
    while (row >= 0 && col < n)
    {
        if (soln[row][col] == 1)
            return false;
        row--;
        col++;
    }

    return true;
}

bool nqueens(int soln[10][10], int i, int n)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    bool flag = false;
    for (int j = 0; j < n; j++)
    {
        if (isSafe(soln, i, j, n))
        {
            soln[i][j] = 1;
            if (nqueens(soln, i + 1, n) == true) {
                soln[i][j] = 0;
                flag = true;
            }
            soln[i][j] = 0;
        }
    }
    return flag;
}

bool nqueens1(int soln[10][10], int i, int n)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(soln, i, j, n))
        {
            soln[i][j] = 1;
            if (nqueens1(soln, i + 1, n) == true) {
                // soln[i][j]=0;
                return true;
            }
            soln[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int soln[10][10] = {0};
    int n = 6;
    nqueens(soln, 0, n);
}
