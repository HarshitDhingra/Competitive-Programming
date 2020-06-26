#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<long long int>pq;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        if (z == 1)
        {
            long long int x, y;
            cin >> x >> y;
            long long int v = ((x * x) + (y * y));
            pq.push(v);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        if (z == 2)
        {
            cout << pq.top() << "\n";
        }
    }
}