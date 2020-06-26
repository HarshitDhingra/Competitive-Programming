#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>ans;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int j = 0;
    set<int>s;
    for (int i = 0; i < n; i++)
    {
        while (j < n  && s.find(v[j]) == s.end())
        {
            s.insert(v[j]);
            j++;
        }
        s.erase(v[i]);
        ans.push_back(j - i);
    }
    long long int sum = 0;
    for (auto i : ans)
    {
        sum = sum + (i * (i + 1)) / 2;
        sum = sum % mod;
        //cout<<i<<" ";
    }
    cout << sum << "\n";
    return 0;
}