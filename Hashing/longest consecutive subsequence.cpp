#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    unordered_set<int>s;

    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i] - 1) != s.end()) {
            continue;
        }
        else {
            int count = 0;
            int x = a[i];
            while (s.find(x) != s.end())
            {
                count++;
                x++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(a, n);
}
