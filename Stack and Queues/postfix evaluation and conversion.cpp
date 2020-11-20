#include <bits/stdc++.h>
using namespace std;

int operation(int x, int y, char z) {

    if (z == '+') {
        return x + y;
    }
    else if (z == '-') {
        return x - y;
    }
    else if (z == '*') {
        return x * y;
    }
    else if (z == '/') {
        return x / y;
    }
    return 0;
}

void solve(string s) {

    stack<int>val;
    stack<string>infix;
    stack<string>prefix;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

            int x = val.top();
            val.pop();
            int y = val.top();
            val.pop();

            int temp = operation(y, x, s[i]);
            val.push(temp);

            string a = infix.top();
            infix.pop();
            string b = infix.top();
            infix.pop();

            string c = '(' + b + s[i] + a + ')';
            infix.push(c);

            a = prefix.top();
            prefix.pop();
            b = prefix.top();
            prefix.pop();

            c = s[i] + b + a;
            prefix.push(c);

        }
        else {
            val.push(s[i] - '0');
            string temp(1, s[i]);
            infix.push(temp);
            prefix.push(temp);
        }

    }

    cout << val.top() << endl;
    cout << infix.top() << endl;
    cout << prefix.top();

}

int main() {

    string s;
    getline(cin, s);

    solve(s);

}
