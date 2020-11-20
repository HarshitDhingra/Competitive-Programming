#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j) {

    if ((i == 3 and j == 0) || (i == 3 and j == 2)) {
        return false;
    }

    if (i >= 0 && i < 4 && j >= 0 && j < 3) {
        return true;
    }

    return false;
}

long long solve(int n) {

    vector<vector<int>>curr(4, vector<int>(3, 0));
    vector<vector<int>>next(4, vector<int>(3, 0));

    long long ans = 0;

    for (int m = 1; m <= n; m++) {
        ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {

                if ((i == 3 && j == 0) || (i == 3 && j == 2)) {
                    next[i][j] = 0;
                    continue;
                }

                if (m == 1) {
                    next[i][j] = 1;
                }
                else {
                    if (isSafe(i - 1, j)) {
                        next[i][j] += curr[i - 1][j];
                    }
                    if (isSafe(i + 1, j)) {
                        next[i][j] += curr[i + 1][j];
                    }
                    if (isSafe(i, j - 1)) {
                        next[i][j] += curr[i][j - 1];
                    }
                    if (isSafe(i, j + 1)) {
                        next[i][j] += curr[i][j + 1];
                    }
                    if (isSafe(i, j)) {
                        next[i][j] += curr[i][j];
                    }

                }
                ans += next[i][j];
            }

        }
        curr = next;
        vector<vector<int>>temp(4, vector<int>(3, 0));
        next = temp;
    }

    return ans;
}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int k;
    cin >> k;

    cout << solve(n);

    return 0;
}