#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {

    int s = 0;
    int b = 0;
    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) {
            s++;
        }
        else {
            profit += v[s] - v[b];
            b = s = i;
        }
    }
    profit += v[s] - v[b];

    return profit;
}

int solve1(vector<int>& v, int n) {

    int profit = 0;

    for (int i = 0; i < n - 1; i++) {
        if (v[i] <= v[i + 1]) {
            profit += v[i + 1] - v[i];
        }
    }

    return profit;
}

int main() {

    int n;
    cin >> n;

    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << solve1(v, n);

    return 0;
}