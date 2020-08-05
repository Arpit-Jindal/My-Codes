#include<bits/stdc++.h>
using namespace std;
void printVector(vector<vector<int>> dp) {
	for (auto i : dp) {
		for (auto j : i) {
			cout << j << '\t';
		}
		cout << "\n";
	}
}
//recursive
int LCS_recursive(char* a, char* b) {
	if (a[0] == '\0' || b[0] == '\0') return 0;

	if (a[0] == b[0])
		return 1 + LCS_recursive(a + 1, b + 1);
	else
		return max(LCS_recursive(a, b + 1), LCS_recursive(a + 1, b));
}
// topDown
int LCS_topdown(char* a, char* b, int n, int m, vector<vector<int>>& dp) {
	if (n == 0 || m == 0) return 0;
	if (dp[n][m] != -1) return dp[n][m];
	int ans;
	if (a[0] == b[0])
		ans = 1 + LCS_topdown(a + 1, b + 1, n - 1, m - 1, dp);
	else {
		int option1 = LCS_topdown(a + 1, b, n - 1, m, dp);
		int option2 = LCS_topdown(a, b + 1, n, m - 1, dp);
		ans = max(option1, option2);
	}
	dp[n][m] = ans;
	return ans;
}
// bottomUp
int LCS(char* a, char* b) {
	int n = strlen(a);
	int m = strlen(b);
	vector<vector<int>> dp (n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printVector(dp);
	return dp[n][m];
}
int main() {
	char a[100];
	char b[100];
	cin >> a >> b;
	// cout << LCS_recursive(a, b) << '\n';

	int n = strlen(a);
	int m = strlen(b);
	vector<vector<int>> dp (n + 1, vector<int>(m + 1, -1));
	cout << LCS_topdown(a, b, n, m, dp) << '\n';
	printVector(dp);
	cout << LCS(a, b) << '\n';
}