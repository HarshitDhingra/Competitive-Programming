#include <iostream>
using namespace std;

void subsequences(char input[], int i, char output[], int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << "  ";
        return ;
    }

    subsequences(input, i + 1, output, j);
    output[j] = input[i];
    subsequences(input, i + 1, output, j + 1);

}

int main() {
    char input[] = "abc";
    char output[100];
    subsequences(input, 0, output, 0);
}
