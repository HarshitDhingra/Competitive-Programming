#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    priority_queue<pair<int, int>>pq;
    map<int, int>m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pq.push({v[i], i});
        m[v[i]] = i;
    }
    int i = 0;
    while (!pq.empty() && k > 0)
    {
        int temp = pq.top().first;
        // int index=pq.top().second;
        int index = m[temp];
        if (v[i] != temp)
        {
            m[v[i]] = index;
            m[temp] = i;
            swap(v[i], v[index]);
            k--;
        }
        i++;
        pq.pop();
        // cout<<endl;
    }
    for (int x : v)
    {
        cout << x << " ";
    }
}