#include<iostream>
using namespace std;
int tiles(int n) {
	if (n == 1 || n == 2) return n;
	return tiles(n - 1) + tiles(n - 2);
}
int tiles(int n, int m) {
	if (m > n) return 1;
	if (m == n) return 2;
	return tiles(n - 1, m) + tiles(n - m, m);
}
int main()
{
	cout << tiles(7, 4);
}