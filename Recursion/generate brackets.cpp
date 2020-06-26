#include <iostream>
using namespace std;

void generate_brackets(int open, int close, char output[], int j, int n)
{
    if (j == 2 * n)
    {
        output[j] = '\0';
        cout << output << endl;
        return ;
    }

    if (open < n)
    {
        output[j] = '(';
        generate_brackets(open + 1, close, output, j + 1, n);
    }
    if (close < open)
    {
        output[j] = ')';
        generate_brackets(open, close + 1, output, j + 1, n);
    }
    return ;

}

int main() {
    int n = 6;
    char output[1000];
    generate_brackets(0, 0, output, 0, n);
}
