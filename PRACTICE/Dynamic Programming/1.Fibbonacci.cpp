#include<bits/stdc++.h>
using namespace std;
int fib_recursive(int n) {
	if (n == 0 || n == 1) return 1;
	return fib_recursive(n - 1) + fib_recursive(n - 2);
}
int fib_topdown(int n, int* dp) {
	if (n == 0 || n == 1) return 1;
	if (dp[n] != -1) return dp[n];
	dp[n] = fib_topdown(n - 1, dp) + fib_topdown(n - 2, dp);
	return dp[n];
}
int fib_bottomUp(int n) {
	int dp[n + 1];
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
int fib_noMemory(int n) {
	if (n == 0 || n == 1) return 1;
	int a = 1, ans = 1, temp;
	for (int i = 2; i <= n; i++) {
		temp = a;
		a = ans;
		ans = temp + a;
	}
	return ans;
}
int main() {
	int n; cin >> n;
	int* dp = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = -1;
	}
	cout << fib_topdown(n, dp) << endl;
	delete[] dp;
	cout << fib_bottomUp(n) << endl;
	cout << fib_noMemory(n) << endl;
}