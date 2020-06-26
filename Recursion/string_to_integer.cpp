#include <bits/stdc++.h>
using namespace std;

int stringtoint(char a[], int n)
{
	if (n < 0)
		return 0;

	int ans = 0;
	int sub = stringtoint(a, n - 1);
	ans = sub * 10 + (a[n] - '0');

	return ans;

}

int main() {
	char a[] = "123";
	int n = strlen(a);
	cout << stringtoint(a, n - 1);

}
