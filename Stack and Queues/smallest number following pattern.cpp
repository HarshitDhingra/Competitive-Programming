#include <bits/stdc++.h>
using namespace std;

void solve(string s) {

    stack<int>st;
    int temp = 1;
    string ans;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == 'd') {
            st.push(temp);
            temp++;
        }
        else {

            st.push(temp);
            temp++;

            while (st.size() > 0) {

                ans.push_back(st.top() + '0');
                st.pop();
            }
        }
    }

    st.push(temp);
    temp++;

    while (st.size() > 0) {

        ans.push_back(st.top() + '0');
        st.pop();
    }

    cout << ans;
}

int main() {

    string s;
    cin >> s;

    solve(s);

}