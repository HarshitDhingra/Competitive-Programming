#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int n)
{
    unordered_map<int, int>m;

    int prefix_sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += a[i];

        if (prefix_sum == 0)
            ans = max(ans, i + 1);

        if (m.find(prefix_sum) != m.end())
            ans = max(ans, i - m[prefix_sum]);
        else
            m[prefix_sum] = i;
    }
    return ans;
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
