#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v)
{
    int n = v.size();

    int inc = v[0];
    int exc = 0;

    for (int i = 1; i < n; i++) {

        int ninc = exc + v[i];
        int nexc = max(inc, exc);

        inc = ninc;
        exc = nexc;
    }
    return max(inc, exc);
}

int solve1(vector<int>& nums)
{
    //works for all test cases

    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    vector<int>dp(n + 1);

    dp[0] = max(nums[0], 0);

    for (int i = 1; i < n; i++) {
        int x = dp[i - 1];
        int y = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);

        dp[i] = max(x, y);
    }
    return dp[n - 1];
}

int solve2(vector<int>& nums)
{

    //works only on positive numbers  edge test case [ -1 -1 5 -3 -3 ]

    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    vector<int>dp(n + 1);

    dp[0] = max(nums[0], 0);

    for (int i = 1; i < n; i++) {
        int x = dp[i - 1];
        int y = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);

        dp[i] = max(x, y);
    }
    return dp[n - 1];
}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solve(v);

    return 0;
}