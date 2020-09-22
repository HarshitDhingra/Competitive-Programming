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
    int maxi = 0;

    for (int j = m - 1; j >= 0; j--) {
        for (int i = n - 1; i >= 0; i--) {

            if (j == m - 1) {
                dp[i][j] = v[i][j];
            }
            else if (i == n - 1) {
                dp[i][j] = v[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            else if (i == 0) {
                dp[i][j] = v[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else {
                dp[i][j] = v[i][j] + max(dp[i][j + 1], max(dp[i + 1][j + 1], dp[i - 1][j + 1]));
            }
            //cout<<dp[i][j]<<" ";
            maxi = max(maxi, dp[i][j]);
        }
    }
    cout << maxi << endl;

    queue<Pair>q;

    for (int i = 0; i < n; i++) {
        if (dp[i][0] == maxi) {
            q.push(Pair(i, 0, to_string(i)));
        }
    }

    while (q.size() > 0) {

        Pair temp = q.front();
        q.pop();

        int ci = temp.i;
        int cj = temp.j;

        if (cj == m - 1) {
            cout << temp.path << endl;
        }
        else if (ci == n - 1) {
            if (dp[ci][cj + 1] > dp[ci - 1][cj + 1]) {
                q.push(Pair(ci, cj + 1, temp.path + " d2"));
            }
            else if (dp[ci][cj + 1] < dp[ci - 1][cj + 1]) {
                q.push(Pair(ci - 1, cj + 1, temp.path + " d1"));
            }
            else {
                q.push(Pair(ci - 1, cj + 1, temp.path + " d1"));
                q.push(Pair(ci, cj + 1, temp.path + " d2"));
            }
        }
        else if (ci == 0) {
            if (dp[ci][cj + 1] > dp[ci + 1][cj + 1]) {
                q.push(Pair(ci, cj + 1, temp.path + " d2"));
            }
            else if (dp[ci][cj + 1] < dp[ci + 1][cj + 1]) {
                q.push(Pair(ci + 1, cj + 1, temp.path + " d3"));
            }
            else {
                q.push(Pair(ci, cj + 1, temp.path + " d2"));
                q.push(Pair(ci + 1, cj + 1, temp.path + " d3"));
            }
        }
        else {
            if (dp[ci - 1][cj + 1] >= dp[ci][cj + 1] && dp[ci - 1][cj + 1] >= dp[ci + 1][cj + 1]) {
                q.push(Pair(ci - 1, cj + 1, temp.path + " d1"));
            }
            if (dp[ci][cj + 1] >= dp[ci - 1][cj + 1] && dp[ci][cj + 1] >= dp[ci + 1][cj + 1]) {
                q.push(Pair(ci, cj + 1, temp.path + " d2"));
            }
            if (dp[ci + 1][cj + 1] >= dp[ci][cj + 1] && dp[ci + 1][cj + 1] >= dp[ci - 1][cj + 1]) {
                q.push(Pair(ci + 1, cj + 1, temp.path + " d3"));
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