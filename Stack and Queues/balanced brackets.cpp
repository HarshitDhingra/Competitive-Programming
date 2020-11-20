#include <bits/stdc++.h>
using namespace std;

void solve(string s) {

    int n = s.length();

    stack<char>st;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            if (st.size() > 0 and st.top() == '(') {
                st.pop();
            }
            else {
                cout << "false\n";
                return ;
            }
        }
        else if (s[i] == ']') {
            if (st.size() > 0 and st.top() == '[') {
                st.pop();
            }
            else {
                cout << "false\n";
                return ;
            }
        }
        else if (s[i] == '}') {
            if (st.size() > 0 and st.top() == '{') {
                st.pop();
            }
            else {
                cout << "false\n";
                return ;
            }
        }

    }
    if (st.size() == 0) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
}

int main() {

    string s;
    getline(cin, s);

    solve(s);

}
