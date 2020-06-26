#include <iostream>
using namespace std;

int rec(int n)
{
	if (n == 1)
		return 2;

	if (n == 0)
		return 1;

	int ans = 0;
	ans += rec(n - 1) + rec(n - 2);

	return ans;
}


int main() {

	int n = 3;
	cout << rec(n);

}
