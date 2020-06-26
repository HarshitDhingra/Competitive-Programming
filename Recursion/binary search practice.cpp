#include <iostream>
using namespace std;

int binary_search(int a[], int l, int r, int x)
{
	if (l > r) {
		return -1;
	}
	int mid = (l + r) / 2;
	if (a[mid] == x)
		return mid;

	if (a[mid] > x)
		return binary_search(a, l, mid - 1, x);

	return binary_search(a, mid + 1, r, x);
}

int power(int a, int b)
{
	if (b == 0)
		return 1;

	return a * power(a, b - 1);
}

int mul(int a, int b)
{
	if (b == 0)
		return 0;

	return a + mul(a, b - 1);
}

int first_Occur(int a[], int n, int key)
{
	if (n < 0)
		return -1;

	int temp = first_Occur(a, n - 1, key);
	if (temp != -1)
	{
		return temp;
	}
	if (a[n] == key)
		return n;

	return -1;
}

int last_Occur(int a[], int n, int key)
{
	if (n < 0)
		return -1;

	if (a[n] == key)
		return n;

	return last_Occur(a, n - 1, key);
}

void allOccur(int a[], int n, int key)
{
	if (n < 0)
		return;

	if (a[n] == key)
		cout << n << " ";

	allOccur(a, n - 1, key);
}

int fast_power(int a, int n)
{
	if (n == 0)
		return 1;

	if (n & 1) {
		int temp = fast_power(a, n / 2);
		return a * temp * temp;
	}
	else {
		int temp = fast_power(a, n / 2);
		return temp * temp;
	}
}

int main() {
	// cout << power(2, 5);
	// cout << endl << mul(2, 9);

	// int a[]={1,2,3,4,7,9,11};
//    cout<<binary_search(a,0,7,2);
	int a[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
	int n = sizeof(a) / sizeof(int);
	int key = 7;
	// cout << first_Occur(a, n - 1, key);
	// cout << last_Occur(a, n - 1, key);
	// allOccur(a,n,key);
	cout << fast_power(2, 10);

}
