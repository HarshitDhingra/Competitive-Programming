#include <iostream>
using namespace std;

void rec(char soln[], int j, int open, int close, int n)
{
    if (j == 2 * n)
    {
        soln[j] = '\0';
        cout << soln << endl;
        return ;
    }

    if (open > close)
    {
        soln[j] = ')';
        rec(soln, j + 1, open, close + 1, n);
    }
    if (open < n)
    {
        soln[j] = '(';
        rec(soln, j + 1, open + 1, close, n);
    }

}

int main() {
    char soln[100];
    int n;
    cin >> n;
    rec(soln, 0, 0, 0, n);

}
