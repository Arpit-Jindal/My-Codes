#include<iostream>
using namespace std;
int permutationCoefficient(int n, int k) {
	if (k > n) return 0;
	if (k == 0)
		return 1;
	return permutationCoefficient(n - 1, k) + k * permutationCoefficient(n - 1, k - 1);
}
int main()
{
	cout << permutationCoefficient(10, 2);
}