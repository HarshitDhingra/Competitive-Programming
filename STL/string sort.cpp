#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
	for (int i = 0; i < min(a.length(), b.length()); i++)
	{
		if (a[i] != b[i])
			return a < b;
	}
	if (a.length() < b.length())
		return false;
	else return true;
}

int main() {
	int n;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	for (string i : v)
	{
		cout << i << "\n";
	}
	return 0;
}