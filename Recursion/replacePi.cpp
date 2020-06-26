#include <iostream>
using namespace std;

void replacePi(char a[], int i)
{
    if (a[i] == '\0')
        return;

    if (a[i] == 'p' && a[i + 1] == 'i')
    {
        int k = i + 2;
        while (a[k] != '\0')
        {
            k++;
        }

        for (int j = k; j >= i + 2; j--)
        {
            a[j + 2] = a[j];
        }
        a[i] = '3'; a[i + 1] = '.'; a[i + 2] = '1'; a[i + 3] = '4';
        replacePi(a, i + 4);
    }
    else
    {
        replacePi(a, i + 1);
    }
}

int main() {

    char a[100] = "pixyzpipinvvpi";
    replacePi(a, 0);
    cout << a;

}
