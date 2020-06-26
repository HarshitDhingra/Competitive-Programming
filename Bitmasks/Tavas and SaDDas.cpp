#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 0, pos = 0;
	while (n > 0)
	{
		int temp = n % 10;
		if (temp == 7)
		{
			ans += 1 << pos;
		}
		n = n / 10;
		pos++;
	}
	ans += (1 << pos) - 2;
	cout << ans + 1 << endl;
}
