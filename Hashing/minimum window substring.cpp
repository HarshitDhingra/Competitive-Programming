#include <bits/stdc++.h>
using namespace std;

string solve(string s, string p)
{
    int sl = s.length();
    int pl = p.length();

    if (pl > sl) {
        return "none";
    }

    int fs[256] = {0};
    int fp[256] = {0};

    for (int i = 0; i < pl; i++)
    {
        fp[p[i]]++;
    }

    int start = 0, x = 0, ans = INT_MAX;
    int count = 0;
    for (int i = 0; i < sl; i++)
    {
        char ch = s[i];
        fs[ch]++;

        if (fp[ch] != 0 && fs[ch] <= fp[ch]) {
            count++;
        }

        if (count == pl)
        {
            while (fp[s[start]] == 0 || fp[s[start]] < fs[s[start]]) {
                fs[s[start]]--;
                start++;
            }
            if (ans > i - start + 1) {
                ans = i - start + 1;
                x = start;
            }
        }
    }
    if (ans == INT_MAX) {
        return "none";
    }
    cout << ans << endl;
    return s.substr(x, ans);
}

int main() {
    string s;;
    string p;
    cin >> s >> p;

    cout << solve(s, p);
}
