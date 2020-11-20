#include <bits/stdc++.h>
using namespace std;

int solve(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    int dpt[n][n];
    int dpf[n][n];

    memset(dpt, 0, sizeof(dpt));
    memset(dpf, 0, sizeof(dpf));

    for (int d = 0; d < n; d++) {

        int i = 0;
        int j = d;

        while (j < n) {

            if (d == 0) {
                if (s1[i] == 'T') {
                    dpt[i][j] = 1;
                    dpf[i][j] = 0;
                }
                else {
                    dpt[i][j] = 0;
                    dpf[i][j] = 1;
                }
            }
            else {

                for (int k = i; k < j; k++) {
                    if (s2[k] == '|') {

                        dpt[i][j] += dpt[i][k] * dpt[k + 1][j];
                        dpt[i][j] += dpt[i][k] * dpf[k + 1][j];
                        dpt[i][j] += dpf[i][k] * dpt[k + 1][j];

                        dpf[i][j] += dpf[i][k] * dpf[k + 1][j];
                    }
                    else if (s2[k] == '&') {

                        dpt[i][j] += dpt[i][k] * dpt[k + 1][j];

                        dpf[i][j] += dpt[i][k] * dpf[k + 1][j];
                        dpf[i][j] += dpf[i][k] * dpt[k + 1][j];
                        dpf[i][j] += dpf[i][k] * dpf[k + 1][j];

                    }
                    else if (s2[k] == '^') {

                        dpt[i][j] += dpt[i][k] * dpf[k + 1][j];
                        dpt[i][j] += dpf[i][k] * dpt[k + 1][j];

                        dpf[i][j] += dpt[i][k] * dpt[k + 1][j];
                        dpf[i][j] += dpf[i][k] * dpf[k + 1][j];

                    }

                }

            }

            i++; j++;
        }

    }

    return dpt[0][n - 1];
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    cout << solve(s1, s2);

    return 0;
}