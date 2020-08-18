#include <bits/stdc++.h>
using namespace std;

void buildtree(int *a, int s, int e, int *tree, int index)
{
    if (s == e) {
        tree[index] = a[s];
        return ;
    }

    int mid = (s + e) / 2;
    buildtree(a, s, mid, tree, 2 * index);
    buildtree(a, mid + 1, e, tree, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);

}

int query(int* tree, int ss, int se, int qs, int qe, int index)
{
    if (ss >= qs && se <= qe) {
        return tree[index];
    }

    if (ss > qe || se < qs) {
        return INT_MAX;
    }

    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);

    return min(left, right);
}

int main() {

    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);

    int *tree = new int[4 * n + 1];
    buildtree(a, 0, n - 1, tree, 1);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, n - 1, l, r, 1) << endl;
    }
}
