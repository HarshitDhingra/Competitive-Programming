#include <iostream>
using namespace std;

int r, c;

void floodfill(chat mat[][50], int i, int j, char ch, char color)
{

    if (i < 0 || j < 0 || i > r || j >= c)
        return;

    if (mat[i][j] != ch)
        return ;

    mat[i][j] = color;

    floodfill(mat, i + 1, j, ch, color);
    floodfill(mat, i - 1, j, ch, color);
    floodfill(mat, i, j + 1, ch, color);
    floodfill(mat, i, j - 1, ch, color);
}

int main() {

    cin >> r >> c;

    char input[50][50];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> input[i][j];
        }
    }

    floodfill(10, 15);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << input[i][j];
        }
    }

}
