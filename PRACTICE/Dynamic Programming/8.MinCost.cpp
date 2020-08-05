#include<bits/stdc++.h>
using namespace std;

//recursive
int min_cost(vector<vector<int>> input, int si, int sj, int ei, int ej) {
	if (si == ei && sj == ej) return input[si][sj];
	if (si > ei || sj > ej) return 1e9;
	int right = min_cost(input, si, sj + 1, ei, ej);
	int down = min_cost(input, si + 1, sj, ei, ej);
	int diag = min_cost(input, si + 1, sj + 1, ei, ej);
	int ans = min(right, min(down, diag)) + input[si][sj];
	return ans;
}
//optimized - topdown
int min_cost_topdown(vector<vector<int>> input, int si, int sj,
                     int ei, int ej, vector<vector<int>> &dp) {
	if (si == ei && sj == ej) return input[si][sj];
	if (si > ei || sj > ej) return 1e9;
	if (dp[si][sj] > -1) return dp[si][sj];
	int right = min_cost(input, si, sj + 1, ei, ej);
	int down = min_cost(input, si + 1, sj, ei, ej);
	int diag = min_cost(input, si + 1, sj + 1, ei, ej);
	int ans = min(right, min(down, diag)) + input[si][sj];
	dp[si][sj] = ans;
	return ans;
}
//optimized - bottom Up
int min_cost_bottomUp(vector<vector<int>> input) {

	int n = input.size();
	int m = input[0].size();

	//We have to go from (0,0) to (n-1,m-1)
	vector<vector<int>> dp (n, vector<int>(m, -1));

	//Base Values
	dp[n - 1][m - 1] = input[n - 1][m - 1];
	for (int j = m - 2; j >= 0; j--)
		dp[n - 1][j] = input[n - 1][j] + dp[n - 1][j + 1];
	for (int i = n - 2; i >= 0; i--)
		dp[i][m - 1] = input[i][m - 1] + dp[i + 1][m - 1];

	//Main Code
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			dp[i][j] = input[i][j] + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
		}
	}
	return dp[0][0];

}
int main() {
	vector<vector<int>> input =
	{
		{4, 3, 1, 8},
		{1, 8, 2, 5},
		{1, 1, 8, 1},
		{4, 3, 8, 9}
	};
	int n = input.size();
	int m = input[0].size();

	// cout << min_cost(input, 0, 0, n - 1, m - 1) << endl;

	vector<vector<int>> dp (n, vector<int>(m, -1));
	cout << min_cost_topdown(input, 0, 0, n - 1, m - 1, dp) << endl;

	cout << min_cost_bottomUp(input);
}