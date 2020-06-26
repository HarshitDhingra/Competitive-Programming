#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    map<char, int>m;
    for (int i = 0; i < s2.length(); i++)
    {
        m[s2[i]]++;
    }
    int count = s2.length();
    int left = 0, right = 0, start = 0;
    int ans = INT_MAX;
    while (right < s1.length())
    {
        m[s1[right]]--;
        if (m[s1[right]] >= 0)
        {
            count--;
        }
        right++;
        while (count == 0)
        {
            // ans=min(ans,right-left);
            if (right - left < ans)
            {
                start = left;
                ans = right - left;
            }
            m[s1[left]]++;
            if (m[s1[left]] > 0)
            {
                count++;
            }
            left++;
        }
    }
    if (ans == INT_MAX)
        cout << "No String\n";
    else
        cout << s1.substr(start, ans) << "\n";

}