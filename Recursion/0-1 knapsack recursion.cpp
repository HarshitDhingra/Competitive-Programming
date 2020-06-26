#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int n, int x, int sum = 0)
{
    if (x == 0 || n < 0)
        return sum;

    int ans = 0;

    int ans1 = 0, ans2 = 0;
    //excluding
    ans1 = knapsack(wt, val, n - 1, x, sum);
    //including
    if (x >= wt[n])
        ans2 = knapsack(wt, val, n - 1, x - wt[n], sum + val[n]);

    ans = max(ans1, ans2);

    return ans;
}
//2nd approach
int knapsack1(int wt[], int val[], int n, int x)
{
    if (x == 0 || n < 0 )
        return 0;

    int ans = 0, ans1 = 0, ans2 = 0;

    ans1 = knapsack1(wt, val, n - 1, x);

    if (x >= wt[n])
        ans2 = val[n] + knapsack1(wt, val, n - 1, x - wt[n]);

    ans = max(ans1, ans2);

    return ans;
}

int main() {
    int wt[] = {1, 2, 3, 5};
    int val[] = {40, 20, 35, 100};
    int n = 3;
    int x = 6;
    cout << knapsack1(wt, val, n, x);
}
