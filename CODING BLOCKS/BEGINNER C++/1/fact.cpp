#include <iostream>
using namespace std;
int main ()
{
	int n, r;
	cin >> n >> r;
	int ans = 1;
	for (int i = 1; i <= n ; i++) {
		ans = ans * i;
	}
	int rans = 1;
	for (int j = 1; j <= r ; j++) {
		rans = rans * j;

	}
	int nrans = 1;
	for (int k = 1; k <= (n - r); k++) {
		nrans = nrans * k;
	}
	cout << (ans / (rans * nrans));x
}