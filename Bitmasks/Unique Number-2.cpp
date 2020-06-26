#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        res = res ^ v[i];
    }
    int temp = res;
    int i = 0;
    while ((temp & 1) == 0)
    {
        i++;
        temp = temp >> 1;
    }
    int mask = 1 << i;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((mask & v[i]) > 0)
        {
            x = x ^ v[i];
        }
    }
    y = res ^ x;
    cout << min(x, y) << " " << max(x, y) << "\n";
}