#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& a, int n)
{
    unordered_map<int, bool>m;

    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += a[i];

        if (prefix_sum == 0 || m[prefix_sum] == true)
            return true;

        m[prefix_sum] = true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(a, n);
}
