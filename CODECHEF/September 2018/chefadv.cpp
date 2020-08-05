#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	long int k, p;
	for (int i = 0; i < t; i++)
	{
		long int n, m, x, y;
		cin >> n >> m >> x >> y;

		if (n % x == 0 ) k = ((n / x) - 1) * x + 1;
		else if (n % x != 0) k = (n / x) * x + 1;


		if (m % y == 0 ) p = ((m / y) - 1) * y + 1;
		else if (m % y != 0) p = (m / y) * y + 1;

		if (x == 1 && p == m - 1 && n > 1)cout << "Chefirnemo\n";
		else if (y == 1 && k == n - 1 && m > 1)cout << "Chefirnemo\n";
		else if (n == k && m == p)  cout << "Chefirnemo\n";
		else if (n == (k + 1) && m == (p + 1)) 	 cout << "Chefirnemo\n";
		else cout << "Pofik\n";

	}
}