#include <bits/stdc++.h>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string searchIn [] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void rec(char input[], int i, char output[], int j, vector<string>& ans)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        ans.push_back(output);
        //cout<<output<<endl;
        return ;
    }
    int digit = input[i] - '0';
    for (int k = 0; table[digit][k] != '\0'; k++)
    {
        output[j] = table[digit][k];
        rec(input, i + 1, output, j + 1, ans);
    }

}

int main() {
    char input[1000];
    cin >> input;
    char output[1000];
    vector<string>ans;
    rec(input, 0, output, 0, ans);

    for (string i : ans)
    {
        for (int j = 0; j < 10; j++)
        {
            string temp = searchIn[j];
            if (temp.length() >= i.length())
                for (int k = 0; k < temp.length(); k++)
                {
                    string subtemp = temp.substr(k, i.length());
                    if (subtemp == i) {
                        cout << temp << endl;
                        break;
                    }
                }
        }
    }

}
