#include <bits/stdc++.h>
using namespace std;

set<string>s;

void permutation(char input[], int i)
{
    if (input[i] == '\0')
    {
        s.insert(input);
        //cout<<input<<endl;
        return ;
    }
    for (int j = i; input[j] != '\0'; j++)
    {
        swap(input[i], input[j]);
        permutation(input, i + 1);
        swap(input[i], input[j]);
    }
}

int main() {
    char input[1000];
    cin >> input;
    permutation(input, 0);
    for (auto i : s)
    {
        cout << i << endl;
    }

}
