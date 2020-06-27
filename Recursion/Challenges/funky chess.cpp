#include <iostream>
using namespace std;

int row[] = { -2, -2, -1, -1, 1, 1, 2, 2};
int col[] = { -1, 1, -2, 2, -2, 2, -1, 1};

void funkychess(int chess[][11], int i, int j, int n, int count, int &finalans)
{
    if (i >= n || j >= n || i < 0 || j < 0 || chess[i][j] == 0)
        return ;

    finalans = max(finalans, count);

    chess[i][j] = 0;

    for (int k = 0; k <= 7; k++)
    {
        int x = i + row[k];
        int y = j + col[k];

        funkychess(chess, x, y, n, count + 1, finalans);
    }

    chess[i][j] = 1;
}

int main() {
    int chess[11][11];
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> chess[i][j];
            if (chess[i][j] == 1)
                total++;
        }
    int finalans = 1;
    funkychess(chess, 0, 0, n, 1, finalans);
    int ans = total - finalans;
    cout << ans << endl;

    return 0;
}
