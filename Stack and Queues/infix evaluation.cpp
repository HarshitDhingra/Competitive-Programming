#include <bits/stdc++.h>
using namespace std;

int precedence(char x) {

    if (x == '+') {
        return 1;
    }
    else if (x == '-') {
        return 1;
    }
    else if (x == '*') {
        return 2;
    }
    else if (x == '/') {
        return 2;
    }
}
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

}

void solve(string s) {

    stack<char>opt;
    stack<int>opr;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(') {
            opt.push(s[i]);
        }
        else if (isdigit(s[i])) {
            opr.push(s[i] - '0');
        }
        else if (s[i] == ')') {

            while (opt.size() > 0 and opt.top() != '(') {

                int x = opr.top();
                opr.pop();
                int y = opr.top();
                opr.pop();
                char z = opt.top();
                opt.pop();
                int temp = operation(y, x, z);
                opr.push(temp);
            }
            opt.pop();
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

            while (opt.size() > 0 and opt.top() != '(' and precedence(s[i]) <= precedence(opt.top())) {

                int x = opr.top();
                opr.pop();
                int y = opr.top();
                opr.pop();
                char z = opt.top();
                opt.pop();
                int temp = operation(y, x, z);
                opr.push(temp);

            }
            opt.push(s[i]);
        }

    }

    while (opt.size() > 0) {

        int x = opr.top();
        opr.pop();
        int y = opr.top();
        opr.pop();
        char z = opt.top();
        opt.pop();
        int temp = operation(y, x, z);
        opr.push(temp);
    }
    cout << opr.top();
}

int main() {

    string s;
    getline(cin, s);

    solve(s);

}
