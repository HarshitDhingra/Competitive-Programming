#include <bits/stdc++.h>
using namespace std;

double dp[102][102][102];

void init_dp()
{
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++)
            for (int k = 0; k < 102; k++)
                dp[i][j][k] = -1.0;
}

double rock(int r, int p, int s)
{
    if (r == 0 || s == 0) {
        return 0.0;
    }
    if (p == 0) {
        return 1.0;
    }

    if (dp[r][p][s] != -1.0) {
        return dp[r][p][s];
    }

    double total = r * s + p * r + p * s;
    double ans = 0.0;
    ans += rock(r - 1, p, s) * ((r * p) / total);
    ans += rock(r, p - 1, s) * ((p * s) / total);
    ans += rock(r, p, s - 1) * ((r * s) / total);

    dp[r][p][s] = ans;

    return ans;
}

double scissor(int r, int p, int s)
{
    if (p == 0 || s == 0) {
        return 0.0;
    }
    if (r == 0) {
        return 1.0;
    }

    if (dp[r][p][s] != -1.0) {
        return dp[r][p][s];
    }

    double total = r * s + p * r + p * s;
    double ans = 0;
    ans += scissor(r - 1, p, s) * ((r * p) / total);
    ans += scissor(r, p - 1, s) * ((p * s) / total);
    ans += scissor(r, p, s - 1) * ((r * s) / total);

    dp[r][p][s] = ans;

    return ans;
}

double paper(int r, int p, int s)
{
    if (p == 0 || r == 0) {
        return 0.0;
    }
    if (s == 0) {
        return 1.0;
    }

    if (dp[r][p][s] != -1.0) {
        return dp[r][p][s];
    }

    double total = r * s + p * r + p * s;
    double ans = 0.0;
    ans += paper(r - 1, p, s) * ((r * p) / total);
    ans += paper(r, p - 1, s) * ((p * s) / total);
    ans += paper(r, p, s - 1) * ((r * s) / total);

    dp[r][p][s] = ans;

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int r, p, s;
        cin >> r >> s >> p;
        init_dp();
        double ans1 = rock(r, p, s);
        init_dp();
        double ans2 = scissor(r, p, s);
        init_dp();
        double ans3 = paper(r, p, s);

        cout << fixed << setprecision(9) << ans1 << " " << ans2 << " " << ans3 << endl;
    }
}
