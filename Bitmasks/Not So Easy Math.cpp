#include <bits/stdc++.h>
using namespace std;
int main() {
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sets = (1 << 8) - 1;
        int ans = 0;
        for (int i = 1; i <= sets; i++)
        {
            int setbits = __builtin_popcount(i);
            int denom = 1;
            for (int j = 0; j <= 7; j++)
            {
                if (i & (1 << j))
                {
                    denom *= primes[j];
                }
            }
            if (setbits & 1)
            {
                ans += n / denom;
            }
            else
            {
                ans -= n / denom;
            }
        }
        cout << ans << endl;
    }
}
