#include <bits/stdc++.h>
using namespace std;

char alphabet[] = " abcdefghijklmnopqrstuvwxyz";

void generate_strings(char input[], int i, char output[], int j, vector<string>&ans)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        ans.push_back(output);
        //cout << output << endl;
        return ;
    }

    int digit = input[i] - '0';
    int nextdigit = input[i + 1] - '0';

    if (digit == 0)
    {
        generate_strings(input, i + 1, output, j + 1, ans);
    }

    output[j] = alphabet[digit];
    generate_strings(input, i + 1, output, j + 1, ans);

    if (input[i + 1] != '\0' && nextdigit <= 6 && digit <= 2)
    {
        output[j] = alphabet[digit * 10 + nextdigit];
        generate_strings(input, i + 2, output, j + 1, ans);
    }

}

int main() {
    char input[10000];
    cin >> input;
    char output[10000];
    vector<string>ans;
    generate_strings(input, 0, output, 0, ans);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i];
        else
            cout << ans[i] << ", ";
    }
    cout << "]";

    return 0;
}
