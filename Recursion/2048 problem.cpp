#include <bits/stdc++.h>
using namespace std;

void printspellings(int n, vector<string>& a)
{
    if (n == 0)
        return ;

    printspellings(n / 10, a);

    cout << a[n % 10] << " ";
}

int main() {
    int n = 2048;
    vector<string>a = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    printspellings(n, a);


}
