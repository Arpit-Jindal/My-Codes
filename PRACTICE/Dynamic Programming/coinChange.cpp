#include<iostream>
using namespace std;

int numChange2(int n, int *d, int k, int** dp) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	if (k == 0)
		return 0;

	if (dp[n][k] >= 0)
		return dp[n][k];

	int option1 = numChange2(n - d[0], d, k, dp);
	int option2 = numChange2(n, d + 1, k - 1, dp);
	dp[n][k] = option1 + option2;
	return dp[n][k];
}

int numChange(int n, int *d, int k) {//k = total no. of denominations ,d= denomination array
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	if (k == 0)
		return 0;
	int option1 = numChange(n - d[0], d, k);
	int option2 = numChange(n, d + 1, k - 1);
	return option1 + option2;
}
int main() {

}