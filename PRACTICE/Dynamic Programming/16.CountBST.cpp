#include <bits/stdc++.h>
using namespace std;
int m = pow(10, 9) + 7;
int countBST(int n)
{
	long long dp[n + 1];
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			dp[i] = (dp[i] + ((dp[j] % m) * (dp[i - j - 1] % m)) % m) % m;
		}
	}
	return dp[n];
}
int main() {
	int n; cin >> n;
	cout << countBST(n);
}