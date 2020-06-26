#include <iostream>
using namespace std;

int rec(char maze[10][10], int i, int j, int n, int m)
{
    if (i == n && j == m)
        return 1;

    if (i > n || j > m)
        return 0;

    if (maze[i][j] == 'X')
        return 0;

    int ans = 0;
    ans += rec(maze, i, j + 1, n, m) + rec(maze, i + 1, j, n, m);

    return ans;
}

bool ratInMaze(char maze[10][10], int solution[][10], int i, int j, int n, int m)
{
    if (i == n && j == m)
    {
        solution[i][j] = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        solution[i][j] = 0;

        return true;
    }
    if (i > n || j > m)
        return false;

    if (maze[i][j] == 'X')
        return false;

    solution[i][j] = 1;

    bool rightans = ratInMaze(maze, solution, i, j + 1, n, m);
    bool downans = ratInMaze(maze, solution, i + 1, j, n, m);

    solution[i][j] = 0;

    if (rightans == false and downans == false)
        return false;

    return true;

}

int main() {
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int solution[10][10] = {0};
    //cout<<rec(maze,0,0,3,3);

    if (ratInMaze(maze, solution, 0, 0, 3, 3) != true)
        cout << "path does'n exist";
}
