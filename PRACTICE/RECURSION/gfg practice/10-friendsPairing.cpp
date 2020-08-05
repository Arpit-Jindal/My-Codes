#include<iostream>
using namespace std;
int friendsPairing(int n) {
	if (n == 2 || n == 1 || n == 0) return n;
	return friendsPairing(n - 1) + (n-1)*friendsPairing(n - 2);
}
int main()
{
	cout << friendsPairing(4);
}