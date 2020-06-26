#include <iostream>
using namespace std;

void tower(int n, char a, char b, char c)
{
	if (n == 0)
		return ;

	tower(n - 1, a, c, b)   ;
	cout << "shift disk " << n << " from " << a << " to " << c << endl;
	tower(n - 1, b, a, c);
}

int main() {
	int n = 3;
	tower(n, 'a', 'b', 'c');
}
