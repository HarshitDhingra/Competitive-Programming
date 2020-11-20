#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n) {

    if (i >= 0 and j >= 0 and i < n and j < n) {
        return true;
    }
    return false;
}

int dirx[] = { -2, -1, 1, 2, 2, 1, -1, -2};
int diry[] = { 1, 2, 2, 1, -1, -2, -2, -1};

void solve(int n, int k, int r, int c) {

    vector<vector<double>>curr(n, vector<double>(n, 0.0));
    vector<vector<double>>next(n, vector<double>(n, 0.0));
    double ans = 0;

    curr[r][c] = 1;

    for (int m = 1; m <= k; m++) {
        ans = 0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (curr[i][j] != 0) {

                    for (int p = 0; p < 8; p++) {

                        int x = i + dirx[p];
                        int y = j + diry[p];

                        if (isSafe(x, y, n)) {
                            next[x][y] += (double)curr[i][j] / 8;
                        }

                    }
                }

            }
        }
        curr = next;
        vector<vector<double>>temp(n, vector<double>(n, 0.0));
        next = temp;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += curr[i][j];
        }
    }
    cout << setprecision(17) << ans << endl;

    return;
}

int main() {

    int n, k, r, c;
    cin >> n >> k >> r >> c;

    solve(n, k, r, c);

    return 0;
}