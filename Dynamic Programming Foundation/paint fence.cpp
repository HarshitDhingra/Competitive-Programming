#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int k) {

    long long same = k * 1;
    long long diff = k * (k - 1);
    long long total = same + diff;

    for (int i = 3; i <= n; i++) {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }
    return total;
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << solve(n, k);

    return 0;
}