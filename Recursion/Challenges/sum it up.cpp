#include <bits/stdc++.h>
using namespace std;

set<vector<int>>s;

void rec(vector<int>& v , int n, int x, vector<int>& ans)
{
    if (x == 0)
    {
        vector<int>temp = ans;
        sort(temp.begin(), temp.end());
        // for(int k=0;k<ans.size();k++)
        // cout<<ans[k]<<" ";
        // cout<<endl;
        s.insert(temp);
        return ;
    }
    if (x < 0)
    {
        return ;
    }
    if (n < 0)
    {
        return ;
    }

    rec(v, n - 1, x, ans);
    ans.push_back(v[n]);
    rec(v, n - 1, x - v[n], ans);
    ans.pop_back();

}

int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int x;
    cin >> x;
    vector<int>ans;
    rec(v, n - 1, x, ans);
    for (auto i : s)
    {
        for (int j = 0; j < i.size(); j++)
        {
            cout << i[j] << " ";
        }
        cout << endl;
    }


}
