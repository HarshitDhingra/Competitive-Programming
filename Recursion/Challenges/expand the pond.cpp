#include <bits/stdc++.h>
using namespace std;

int groupid = 0;

int rec(int pond[][1001], int i, int j, int n, int m, int visited[][1001])
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return 0;
    if (pond[i][j] == 0)
        return 0;
    if (visited[i][j] == 1)
        return 0;

    int ans = 0;
    visited[i][j] = 1;
    pond[i][j] = groupid;
    ans += 1 + rec(pond, i + 1, j, n, m, visited) + rec(pond, i, j + 1, n, m, visited) + rec(pond, i, j - 1, n, m, visited) + rec(pond, i - 1, j, n, m, visited);

    return ans;
}
bool issafe(int pond[][1001], int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || pond[i][j] == 0)
        return false;

    return true;
}

int count(int pound[][1001], int i, int j, int n, int m, set<int>&s, map<int, int>& hash)
{
    int sum = 1;
    for (int k : s)
    {
        //cout<<k<<" ";
        sum += hash[k];
    }
    //cout<<endl;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    groupid = 10;
    int pond[1001][1001] = {0};
    int visited[1001][1001] = {0};
    int maxi = INT_MIN;
    map<int, int>hash;
    set<int>s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pond[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pond[i][j] == 1 && visited[i][j] == 0) //visited[i][j]==0
            {
                hash[groupid] = rec(pond, i, j, n, m, visited);
                //cout<<hash[groupid]<<endl;
                maxi = max(maxi, hash[groupid]);
                groupid++;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<pond[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pond[i][j] == 0)
            {
                s.clear();
                if (issafe(pond, i + 1, j, n, m))
                {
                    s.insert(pond[i + 1][j]);
                }
                if (issafe(pond, i - 1, j, n, m))
                {
                    s.insert(pond[i - 1][j]);
                }
                if (issafe(pond, i, j + 1, n, m))
                {
                    s.insert(pond[i][j + 1]);
                }
                if (issafe(pond, i, j - 1, n, m))
                {
                    s.insert(pond[i][j - 1]);
                }
                // for(int k:s)
                // cout<<k<<" ";
                int ans = count(pond, i, j, n, m, s, hash);
                maxi = max(maxi, ans);
            }
        }
    }
    cout << maxi << endl;

}