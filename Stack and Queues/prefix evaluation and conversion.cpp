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
    stack<string>postfix;

    for (int i = s.length() - 1; i >= 0; i--) {

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

            int x = val.top();
            val.pop();
            int y = val.top();
            val.pop();

            int temp = operation(x, y, s[i]);
            val.push(temp);

            string a = infix.top();
            infix.pop();
            string b = infix.top();
            infix.pop();

            string c = '(' + a + s[i] + b + ')';
            infix.push(c);

            a = postfix.top();
            postfix.pop();
            b = postfix.top();
            postfix.pop();

            c = a + b + s[i];
            postfix.push(c);

        }
        else {
            val.push(s[i] - '0');
            string temp(1, s[i]);
            infix.push(temp);
            postfix.push(temp);
        }

    }

    cout << val.top() << endl;
    cout << infix.top() << endl;
    cout << postfix.top();

}

int main() {

    string s;
    getline(cin, s);

    solve(s);

}
