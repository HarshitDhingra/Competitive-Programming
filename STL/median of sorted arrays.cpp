#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a(n + n);
	for (int i = 0; i < n + n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	cout << a[n - 1] << "\n";
}