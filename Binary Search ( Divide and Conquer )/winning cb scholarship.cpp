#include <iostream>
using namespace std;

bool isPossible(int n, int m, int x, int y, int mid)
{
    int req = mid * x;
    int avail = m + (n - mid) * y;

    if (req <= avail)
        return true;

    return false;
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int s = 0;
    int e = n;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (isPossible(n, m, x, y, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << endl;
}
