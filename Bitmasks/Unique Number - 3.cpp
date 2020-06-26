#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	vector<int>ans(65, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (v[i] > 0) {
			ans[j] += v[i] & 1;
			v[i] = v[i] >> 1;
			j++;
		}
	}
	//reverse(ans.begin(),ans.end());
	int result = 0;
	int p = 1;
	for (auto i : ans)
	{
		i = i % 3;
		result += i * p;
		p = p * 2;
		//cout<<i<<" ";
	}
	cout << result << "\n";
}
