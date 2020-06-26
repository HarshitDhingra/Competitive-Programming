#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        char a[111], b[111];
        cin >> a >> b;
        string temp;
        int length = strlen(a);
        for (int i = 0; i < length; i++)
        {
            if (a[i] == b[i]) {
                temp = temp + '0';
            }
            else temp = temp + '1';
        }
        cout << temp << endl;
    }
}
