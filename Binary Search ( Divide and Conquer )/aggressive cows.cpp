#include <iostream>
using namespace std;

bool canPlace(int stalls[], int n, int cows, int minlen)
{
    int laststall = stalls[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - laststall >= minlen)
        {
            laststall = stalls[i];
            count++;
            if (count == cows)
                return true;
        }
    }

    return false;
}

int main() {
    int stalls[] = {1, 2, 5, 8, 9};
    int n = 5;
    int cows = 3;

    int s = 0;
    int e = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (canPlace(stalls, n, cows, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    cout << ans << endl;
}
