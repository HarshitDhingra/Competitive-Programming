#include <iostream>
using namespace std;

char map[] = " abcdefghijklmnopqrstuvwxyz";

void generate_strings(char input[], int i, char output[], int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return ;
    }

    int digit = input[i] - '0';
    int nextdigit = input[i + 1] - '0';

    output[j] = map[digit];
    generate_strings(input, i + 1, output, j + 1);

    if (input[i + 1] != '\0' && nextdigit <= 6 && digit <= 2)
    {
        output[j] = map[digit * 10 + nextdigit];
        generate_strings(input, i + 2, output, j + 1);
    }

}

void generate_strings1(char input[], int i, char output[], int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return ;
    }

    int digit = input[i] - '0';
    int nextdigit = input[i + 1] - '0';
    int no = digit * 10 + nextdigit;

    if (digit != 0) {
        output[j] = digit + 'A' - 1;
        generate_strings1(input, i + 1, output, j + 1);
    }
    else {
        generate_strings(input, i + 1, output, j);
    }

    if (input[i + 1] != '\0')
    {
        if (no <= 26)
        {
            output[j] = no + 'A' - 1;
            generate_strings1(input, i + 2, output, j + 1);
        }
    }

}

int main() {
    char input[] = "102";
    char output[100];
    generate_strings1(input, 0, output, 0);

}
