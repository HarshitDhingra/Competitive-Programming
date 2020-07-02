#include <bits/stdc++.h>
using namespace std;

long long solve_optimized(long long n, long long s, long long e, long long l, long long r)
{
    if (e < l || s > r || s > e)
        return 0;
    if (n == 1 | n == 0)
        return n;

    long long mid = (s + e) / 2;
    long long left = solve_optimized(n / 2, s, mid - 1, l, r);
    long long right = solve_optimized(n / 2, mid + 1, e, l, r);
    long long midtemp;
    if (mid >= l && mid <= r)
        midtemp = n % 2;
    else midtemp = 0;

    return left + right + midtemp;
}

int main() {
    long long n;
    cin >> n;
    long long l, r;
    cin >> l >> r;
    long long bits = 0;
    long long temp = n;
    while (temp > 0)
    {
        bits++;
        temp = temp / 2;
    }
    long long s = 1;
    long long e = pow(2, bits) - 1;
    long long ans = solve_optimized(n, s, e, l, r);
    cout << ans << endl;
}
