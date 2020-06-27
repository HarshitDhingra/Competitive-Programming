#include <bits/stdc++.h>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void rec(char input[], int i, char output[], int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return ;
    }
    int digit = input[i] - '0';
    for (int k = 0; table[digit][k] != '\0'; k++)
    {
        output[j] = table[digit][k];
        rec(input, i + 1, output, j + 1);
    }

}

int main() {
    char input[1000];
    cin >> input;
    char output[1000];
    rec(input, 0, output, 0);
}
