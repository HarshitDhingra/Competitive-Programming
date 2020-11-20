#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string>v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    stack<int>s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {

        int x = s.top();
        s.pop();
        int y = s.top();
        s.pop();

        if (v[x][y] == '1') {
            s.push(y);
        }
        else {
            s.push(x);
        }

    }

    int temp = s.top();
    string ans;

    for (int i = 0; i < n; i++) {

        if (i == temp) {
            continue;
        }

        if (v[temp][i] != '0') {
            ans = "none";
            break;
        }
        if (v[i][temp] != '1') {
            ans = "none";
            break;
        }
    }

    if (ans == "none") {
        cout << ans;
    }
    else {
        cout << temp;
    }


}
