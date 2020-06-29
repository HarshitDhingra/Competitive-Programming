#include <iostream>
using namespace std;

int ans = 0;
bool ld[100] = {0};
bool rd[100] = {0};
bool col[100] = {0};

void queens(int i, int n)
{
    if (i == n)
    {
        ans++;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (col[j] == 0 && ld[i - j + n - 1] == 0 && rd[i + j] == 0)
        {
            col[j] = 1; rd[i + j] = 1; ld[i - j + n - 1] = 1;

            queens(i + 1, n);

            col[j] = 0; rd[i + j] = 0; ld[i - j + n - 1] = 0;
        }
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    queens(0, n);
    cout << ans << endl;
}
