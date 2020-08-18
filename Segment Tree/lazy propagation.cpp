#include <bits/stdc++.h>
using namespace std;

int lazy[1000] = {0};

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

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];

        if (ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if (r < ss || l > se) {
        return;
    }

    if (l <= ss && r >= se)
    {
        tree[index] += inc;

        if (ss != se) {
            lazy[2 * index] += inc;
            lazy[2 * index + 1] += inc;
        }
        return ;
    }

    int mid = (ss + se) / 2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
    updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);

}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index)
{
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];

        if (ss != se) {
            lazy[2 * index] = lazy[index];
            lazy[2 * index + 1] = lazy[index];
        }
        lazy[index] = 0;
    }

    if (qs > se || qe < ss) {
        return INT_MAX;
    }

    if (qs <= ss && qe >= se) {
        return tree[index];
    }

    int mid = (ss + se) / 2;
    int left = queryLazy(tree, ss, mid, qs, qe, 2 * index);
    int right = queryLazy(tree, mid + 1, se, qs, qe, 2 * index + 1);

    return min(left, right);
}

int main() {

    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);

    int *tree = new int[4 * n + 1];
    buildtree(a, 0, n - 1, tree, 1);

    updateRangeLazy(tree, 0, n - 1, 0, 2, 10, 1);
    updateRangeLazy(tree, 0, n - 1, 0, 4, 10, 1);

    cout << queryLazy(tree, 0, n - 1, 1, 1, 1) << endl;
    updateRangeLazy(tree, 0, n - 1, 3, 4, 10, 1);
    cout << queryLazy(tree, 0, n - 1, 3, 5, 1) << endl;

}
