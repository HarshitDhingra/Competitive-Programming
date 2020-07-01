#include <iostream>
using namespace std;

int squareroot(int n)
{
    int s = 1, e = n, ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

float exactsquareroot(int n, int p)
{
    int s = 1, e = n;
    float ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (mid * mid == n)
            return mid;

        if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    float inc = 0.1;
    for (int prec = 1; prec <= p; prec++)
    {
        while (ans * ans <= n)
        {
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc / 10;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << squareroot(n) << endl;
    cout << exactsquareroot(n, 5) << endl;
}
