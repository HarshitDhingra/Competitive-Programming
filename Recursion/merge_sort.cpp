#include <iostream>
using namespace std;


void merge(int a[], int s, int e)
{
    int temp[100], k = s, mid = (s + e) / 2;
    int i = s, j = mid + 1;
    while (i <= mid && j <= e)
    {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }
    for (int k = s; k <= e; k++)
    {
        a[k] = temp[k];
    }
}

void merge_sort(int a[], int s, int e)
{
    if (s >= e)
        return ;

    int mid = (s + e) / 2;
    merge_sort(a, s, mid);
    merge_sort(a, mid + 1, e);

    merge(a, s, e);
}

int main() {
    int a[] = {5, 3, 2, 6, 1};
    int n = 5;
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
