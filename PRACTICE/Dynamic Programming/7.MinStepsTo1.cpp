#include<bits/stdc++.h>
using namespace std;
int minSteps(int n, vector<int> &dp) {
	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	int a = minSteps(n - 1, dp) + 1;
	int b = 1e9, c = 1e9;
	if (n % 2 == 0) b = minSteps(n / 2, dp) + 1;
	if (n % 3 == 0) c = minSteps(n / 3, dp) + 1;

	int ans = min(a, min(b, c));
	dp[n] = ans;

	return ans;
}
int steps_bottomUp(int n) {
	vector<int> dp(n + 1);
	dp[1] = 0;
	dp[2] = dp[3] = 1;
	for (int i = 3; i <= n; i++) {
		int a = dp[i - 1];
		int b = 1e9, c = 1e9;
		if (i % 2 == 0) b = dp[i / 2];
		if (i % 3 == 0) c = dp[i / 3];
		dp[i] = min(a, min(b, c)) + 1;
	}
	return dp[n];
}
int main() {
	int n; cin >> n;
	vector<int> dp(n + 1, -1);
	cout << minSteps(n, dp);
}