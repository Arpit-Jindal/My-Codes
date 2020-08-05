#include<iostream>
using namespace std;
int nthfibonacci(int n)
{
	if (n == 1 || n == 2) return 1;
	else return nthfibonacci(n - 1) + nthfibonacci(n - 2);
}
int main()
{
	int n;
	cin >> n;
	cout << nthfibonacci(n);
}