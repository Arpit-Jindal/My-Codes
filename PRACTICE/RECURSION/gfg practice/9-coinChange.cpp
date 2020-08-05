#include<iostream>
using namespace std;
int coinChange(int n, int* s, int m) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	if (m <= 0)return 0;
	// for (int i = 0; i < size; i++)
	return coinChange(n-s[m-1],s,m) + coinChange(n,s,m-1);
}
int main()
{
	int s[4] = {2, 3, 5, 6};
	cout << coinChange(10, s, 4);
}