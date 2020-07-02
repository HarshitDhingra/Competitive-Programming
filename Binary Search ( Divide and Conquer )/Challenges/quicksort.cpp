#include <iostream>
using namespace std;

int partition(int a[], int s, int e)
{
    int pivot = a[e];
    int i = s - 1, j = s;

    while (j <= e - 1)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    swap(a[i + 1], a[e]);
    return i + 1;

    // cout<<i<<" "<<j<<endl;

}

void quicksort(int a[], int s, int e)
{
    if (s >= e )
    {
        return ;
    }

    int p = partition(a, s, e);
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
}

int main() {

    int n;
    cin >> n;
    int a[200005];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
