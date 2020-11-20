#include <bits/stdc++.h>
using namespace std;

void solve(string s) {

    int n = s.length();

    stack<char>st;

    for (int i = 0; i < n; i++) {

        if (s[i] == ')') {
            if (st.size() > 0 and st.top() == '(') {
                cout << "true\n";
                return;
            }
            else {
                while (st.size() > 0 and st.top() != '(') {
                    st.pop();
                }
                st.pop();
            }
        }
        else {
            st.push(s[i]);
        }

    }
    cout << "false\n";
}

int main() {

    string s;
    getline(cin, s);

    solve(s);

}
