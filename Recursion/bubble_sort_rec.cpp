#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    if (n == 1)
        return ;

    for (int k = 0; k < n - 1; k++)
    {
        if (a[k] > a[k + 1])
            swap(a[k], a[k + 1]);
    }

    bubble_sort(a, n - 1);
}

void bubble_sort_recursive(int a[], int j, int n)
{
    if (n == 1)
        return ;

    if (j == n - 1)
    {
        bubble_sort_recursive(a, 0, n - 1);
        return;
    }

    if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);

    bubble_sort_recursive(a, j + 1, n);
}


int main() {
    int a[] = {5, 3, 2, 6, 1};
    int n = 5;
    bubble_sort_recursive(a, 0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
