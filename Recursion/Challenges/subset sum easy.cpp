#include <bits/stdc++.h>
using namespace std;

bool rec(vector<int>&v, int n, int sum)
{
    if (n < 0)
    {
        return false;
    }

    if (rec(v, n - 1, sum))
        return true;
    if ((sum + v[n]) == 0)
        return true;
    if (rec(v, n - 1, sum + v[n]))
        return true;

    return false;
}


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = rec(v, n - 1, 0);
        if (ans)
            cout << "Yes\n";
        else cout << "No\n";
    }

}
