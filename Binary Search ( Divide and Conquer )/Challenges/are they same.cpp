#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b)
{
    if (a == b)
        return true;

    if (a.length() != b.length())
        return false;

    if ((a.length()) % 2 == 1)
        return false;

    int mid = a.length() / 2;
    int ans = solve(a.substr(0, mid), b.substr(mid, mid)) && solve(a.substr(mid, mid), b.substr(0, mid));
    ans = ans || ( solve(a.substr(0, mid), b.substr(0, mid)) && solve(a.substr(mid, mid), b.substr(mid, mid)) );

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a;
        cin >> b;
        if (a == b)
        {
            cout << "YES\n";
            continue;
        }
        if (solve(a, b))
            cout << "YES\n";
        else cout << "NO\n";

    }
}
