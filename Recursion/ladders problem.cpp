#include <iostream>
using namespace std;

int rec(int i, int n)
{
    if (i == n)
    {
        return 1;
    }
    if (i > n)
    {
        return 0;
    }

    int ans = 0;

    for (int j = 1; j <= 3; j++)
    {
        ans += rec(i + j, n);
    }

    return ans;
}

int rec2(int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    int ans = 0;
    ans += rec2(n - 1) + rec2(n - 2) + rec2(n - 3);

    return ans;
}

int main() {

    int n = 4;
    cout << rec2(4);

}
