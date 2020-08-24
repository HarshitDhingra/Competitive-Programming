#include <bits/stdc++.h>
using namespace std;

struct query {
    int L;
    int R;
    int query_no;
    int block_no;
    bool operator < (query &q2)
    {
        if (block_no < q2.block_no)
            return true;
        else if (block_no > q2.block_no)
            return false;
        return R < q2.R;
    }
};

int freq[1000005];
int distinct;

void Add(int ele)
{
    if (freq[ele] == 0)
        distinct++;
    freq[ele]++;
}

void Remove(int ele)
{
    freq[ele]--;
    if (freq[ele] == 0)
        distinct--;
}

void Adjust(int &cur_l, int &cur_r, int L, int R, vector<int>& a)
{
    while (cur_l < L)
    {
        Remove(a[cur_l]);
        cur_l++;
    }
    while (cur_l > L)
    {
        cur_l--;
        Add(a[cur_l]);
    }
    while (cur_r < R)
    {
        cur_r++;
        Add(a[cur_r]);
    }
    while (cur_r > R)
    {
        Remove(a[cur_r]);
        cur_r--;
    }
}

void solve(vector<int>& a, vector<query>& queries)
{
    vector<int>ans(queries.size());
    memset(freq, 0, sizeof(freq));
    distinct = 0;
    sort(queries.begin(), queries.end());

    int cur_l = queries[0].L;
    int cur_r = queries[0].R;
    for (int i = cur_l; i <= cur_r; i++)
    {
        Add(a[i]);
    }
    ans[queries[0].query_no] = distinct;
    for (int i = 1; i < queries.size(); i++)
    {
        Adjust(cur_l, cur_r, queries[i].L, queries[i].R, a);
        ans[queries[i].query_no] = distinct;
    }
    for (auto i : ans)
    {
        cout << i << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    int rn = sqrt(n);
    vector<query>queries(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        queries[i].L = x;
        queries[i].R = y;
        queries[i].query_no = i;
        queries[i].block_no = x / rn;
    }
    solve(a, queries);

}
