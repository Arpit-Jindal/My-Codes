//A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
//Implement a method to count how many possible ways the child can run up to the stairs. 
//You need to return number of possible ways W.
// --> similar to fibonnacci
#include<bits/stdc++.h>
using namespace std;
//topDown
int possibleWays(int n, vector<int> &dp) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	if (dp[n] != -1) return dp[n];
	dp[n] = possibleWays(n - 1, dp) + possibleWays(n - 2, dp) + possibleWays(n - 3, dp);
	return dp[n];
}
//bottomUp
int possibleWays_bottomUp(int n) {
	vector<int> dp(n + 1);
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}
int main() {
	int n; cin >> n;
	vector<int> dp(n + 1, -1);
	cout << possibleWays(n, dp) << endl;
	cout << possibleWays_bottomUp(n) << endl;
}