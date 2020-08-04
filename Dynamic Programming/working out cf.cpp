#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int boy_start[N][N];  //1
int girl_start[N][N]; //2
int boy_end[N][N];    //3
int girl_end[N][N];   //4
int calorie[N][N];

int max_calorie(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            boy_start[i][j] = calorie[i][j] + max(boy_start[i - 1][j], boy_start[i][j - 1]);
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            girl_start[i][j] = calorie[i][j] + max(girl_start[i + 1][j], girl_start[i][j - 1]);
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            boy_end[i][j] = calorie[i][j] + max(boy_end[i + 1][j], boy_end[i][j + 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            girl_end[i][j] = calorie[i][j] + max(girl_end[i - 1][j], girl_end[i][j + 1]);
        }
    }

    int ans = 0;

    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 2; j <= m - 1; j++)
        {
            int subans1 = boy_start[i - 1][j] + boy_end[i + 1][j] + girl_start[i][j - 1] + girl_end[i][j + 1];
            int subans2 = boy_start[i][j - 1] + boy_end[i][j + 1] + girl_start[i + 1][j] + girl_end[i - 1][j];

            int subans = max(subans1, subans2);

            ans = max(ans, subans);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> calorie[i][j];
        }
    }
    cout << max_calorie(n, m);
}
