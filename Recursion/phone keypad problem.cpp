#include <bits/stdc++.h>
using namespace std;

void generate_names(char input[], int i, char output[], int j, vector<string>& dial)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    int digit = input[i] - '0';
    if (digit == 1 || digit == 0)
    {
        generate_names(input, i + 1, output, j, dial);
    }
    for (int k = 0; k < dial[digit].length(); k++)
    {
        output[j] = dial[digit][k];
        generate_names(input, i + 1, output, j + 1, dial);
    }

}


int main() {
    char input[] = "2234";
    char output[100];
    vector<string>dial = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    generate_names(input, 0, output, 0, dial);

}
