#include <bits/stdc++.h>
using namespace std;

void permute(char in[], int i, set<string> &s)
{
    if (in[i] == '\0')
    {
        // cout<<in<<endl;
        s.insert(in);
        return ;
    }

    for (int j = i; in[j] != '\0'; j++)
    {
        swap(in[i], in[j]);
        permute(in, i + 1, s);
        swap(in[i], in[j]);
    }

}

int main() {
    char in[100] = "abb";
    //cin>>in;
    set<string>s;
    permute(in, 0, s);

    for (auto i : s)
    {
        cout << i << " ";
    }

}
