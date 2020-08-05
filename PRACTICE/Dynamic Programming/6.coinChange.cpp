//You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to
// figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
#include<bits/stdc++.h>
using namespace std;
//topDown
int coinChange(vector<int> den, int numD, int n, vector<vector<int>> &dp) {
	if (n == 0) return 1;
	if (n < 0)return 0;
	if (numD == 0) return 0;
	if (dp[n][numD] != -1) return dp[n][numD];

	int ans = coinChange(den, numD, n - den[0], dp);
	den.erase(den.begin());
	ans += coinChange(den, numD - 1, n, dp);

	dp[n][numD] = ans;
	return ans;
}
//bottomUp
int coinChange_bottomUp(vector<int> den, int numD, int n) {
	//numD = den.size();
	vector<vector<int>> dp(numD + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; i++) dp[0][i] = 0;
	for (int i = 0; i <= numD; i++) dp[i][0] = 1;

	for (int row = 1; row <= numD; row++) {
		for (int col = 1; col <= n; col++) {
			dp[row][col] = dp[row - 1][col];

			if (col - den[row - 1] >= 0)
				dp[row][col] += dp[row][col - den[row - 1]];

		}
	}
	return dp[numD][n];
}
int main() {
	int n; cin >> n;
	vector<int> den = {1, 5, 2};
	int numD = den.size();
	vector<vector<int>> dp(n + 1, vector<int>(numD + 1, -1));
	cout << coinChange(den, numD, n, dp) << endl;
	cout << coinChange_bottomUp(den, numD, n) << endl;
}