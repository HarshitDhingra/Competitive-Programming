#include <iostream>
using namespace std;

int ans = 0, done;

void nqueen_optimized(int rowmask, int ld, int rd)
{
    if (rowmask == done)
    {
        ans++;
        return;
    }
    int safe = done & (~ ( rowmask | ld | rd ) );
    while (safe)
    {
        int p = safe & (-safe);
        safe = safe - p;
        nqueen_optimized(rowmask | p, ( ld | p) << 1, ( rd | p) >> 1 );
    }
}

int main() {
    int n = 10;
    done = (1 << n) - 1;
    nqueen_optimized(0, 0, 0);
    cout << ans << endl;
}
