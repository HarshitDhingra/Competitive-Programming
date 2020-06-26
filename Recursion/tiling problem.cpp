#include <iostream>
using namespace std;

int rec(int n)
{
	if (n <= 3)
		return 1;

	int ans = 0;

	ans += rec(n - 1) + rec(n - 4);

	return ans;
}

int main() {

	int n = 10;
	cout << rec(n);

}
