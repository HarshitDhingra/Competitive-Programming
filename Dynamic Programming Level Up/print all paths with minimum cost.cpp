#include<bits/stdc++.h>
using namespace std;

class Pair {
public:
    int i;
    int j;
    string path;

    Pair(int x, int y, string t) {
        i = x;
        j = y;
        path = t;
    }

};

int solve(int v[][501], int n, int m) {

    int dp[501][501];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            if (i == n - 1 && j == m - 1) {
                dp[i][j] = v[i][j];
            }
            else if (i == n - 1) {
                dp[i][j] = v[i][j] + dp[i][j + 1];
            }
            else if (j == m - 1) {
                dp[i][j] = v[i][j] + dp[i + 1][j];
            }
            else {
                dp[i][j] = v[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[0][0] << endl;

    queue<Pair>q;
    q.push(Pair(0, 0, ""));

    while (q.size() > 0) {

        Pair temp = q.front();
        //cout<<temp.i<<" "<<temp.j<<endl;
        q.pop();

        if (temp.i == n - 1 && temp.j == m - 1) {
            cout << temp.path << endl;
        }
        else if (temp.i == n - 1) {
            q.push(Pair(temp.i, temp.j + 1, temp.path + 'H'));
        }
        else if (temp.j == m - 1) {
            q.push(Pair(temp.i + 1, temp.j, temp.path + 'V'));
        }
        else {
            if (dp[temp.i + 1][temp.j] < dp[temp.i][temp.j + 1]) {
                q.push(Pair(temp.i + 1, temp.j, temp.path + 'V'));
            }
            else if (dp[temp.i + 1][temp.j] > dp[temp.i][temp.j + 1]) {
                q.push(Pair(temp.i, temp.j + 1, temp.path + 'H'));
            }
            else {
                q.push(Pair(temp.i + 1, temp.j, temp.path + 'V'));
                q.push(Pair(temp.i, temp.j + 1, temp.path + 'H'));
            }
        }
    }
    return dp[0][0];
}

int main() {
    int n, m;
    cin >> n >> m;
    int v[501][501];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    solve(v, n, m);

    return 0;
}