#include <iostream>
using namespace std;

int dp[100];

int no_of_bst(int n)
{
    if (n <= 1) {
        return 1;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += no_of_bst(i - 1) * no_of_bst(n - i);
    }
    dp[n] = ans;

    return ans;
}

int factorial(int n)
{
    if (n == 1) {
        return n;
    }
    return n * factorial(n - 1);
}

int no_of_binarytree(int n)
{
    return no_of_bst(n) * factorial(n);
}

//Catalan number -> 2nCn/n+1

int main() {
    int n;
    cin >> n;
    cout << no_of_bst(n) << endl;
    cout << no_of_binarytree(n);
}
