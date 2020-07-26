#include <bits/stdc++.h>
using namespace std;

struct sparse_table {

    vector<vector<int>>mat;
    int n, m;
    vector<int>log;

    void init(int x, int y)
    {
        n = x; m = y;
        mat.resize(n);
        for (int i = 0; i < n; i++)
            mat[i].resize(m);
        log.resize(n + 1);
        for (int i = 2; i < n; i++)
        {
            log[i] = log[i / 2] + 1;
        }
    }

    void build(int a[])
    {
        for (int i = 0; i < n; i++)
        {
            mat[i][0] = a[i];
        }

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r)
    {
        int pw = log[r - l];
        return min(mat[l][pw], mat[r - (1 << pw) + 1][pw]);
    }

};

int main() {
    sparse_table s;
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    s.init(7, 5);
    s.build(a);
    cout << s.query(3, 5);

}
