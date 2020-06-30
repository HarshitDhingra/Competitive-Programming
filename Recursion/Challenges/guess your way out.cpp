#include <bits/stdc++.h>
using namespace std;

void solve(int h, int n)
{
    long long exitpos = pow(2, h) - 1 + n;
    long long ans = 0;

    for (int i = h; i > 0; i--)
    {
        if (exitpos % 2 == 1)
        {
            if ((exitpos / 2) % 2 == 1)
            {
                ans += pow(2, h - i + 1);
            }
            else {
                ans++;
            }
            exitpos = exitpos / 2;
        }
        else
        {
            if ((exitpos / 2) % 2 == 1)
            {
                ans++;
            }
            else {
                ans += pow(2, h - i + 1);
            }
            exitpos = exitpos / 2;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int h, n;
        cin >> h >> n;
        solve(h, n);
    }
}
