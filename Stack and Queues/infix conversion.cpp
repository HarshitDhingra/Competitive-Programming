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

void solve(string s) {

    stack<string>pre;
    stack<string>post;
    stack<char>opt;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(') {
            opt.push(s[i]);
        }
        else if (s[i] >= 'a' and s[i] <= 'z') {

            string temp(1, s[i]);
            pre.push(temp);
            post.push(temp);
        }
        else if (s[i] == ')') {

            while (opt.size() > 0 and opt.top() != '(') {

                string x = pre.top();
                pre.pop();
                string y = pre.top();
                pre.pop();
                char z = opt.top();
                opt.pop();
                string temp = z + y + x;
                pre.push(temp);

                x = post.top();
                post.pop();
                y = post.top();
                post.pop();
                temp = y + x + z;
                post.push(temp);

            }
            opt.pop();
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

            while (opt.size() > 0 and opt.top() != '(' and precedence(s[i]) <= precedence(opt.top())) {

                string x = pre.top();
                pre.pop();
                string y = pre.top();
                pre.pop();
                char z = opt.top();
                opt.pop();
                string temp = z + y + x;
                pre.push(temp);

                x = post.top();
                post.pop();
                y = post.top();
                post.pop();
                temp = y + x + z;
                post.push(temp);
            }
            opt.push(s[i]);
        }

    }

    while (opt.size() > 0) {

        string x = pre.top();
        pre.pop();
        string y = pre.top();
        pre.pop();
        char z = opt.top();
        opt.pop();
        string temp = z + y + x;
        pre.push(temp);

        x = post.top();
        post.pop();
        y = post.top();
        post.pop();
        temp = y + x + z;
        post.push(temp);
    }
    cout << post.top() << endl;
    cout << pre.top();
}

int main() {

    string s;
    getline(cin, s);

    solve(s);

}
