#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z) {
	if (x < y)
		return (x < z) ? x : z;
	else
		return (y < z) ? y : z;
}
int mincost_dp(int**cost, int m, int n) {
	int **dp = new int*[m];
	for (int i = 0; i < m; i++) {
		dp[i] = new int[n];
	}
	//Fill the destination i.e. last cell
	dp[m - 1][n - 1] = cost[m - 1][n - 1];

	//Fill last row (right to left)
	for (int col = n - 2; col >= 0; col--) {
		dp[m - 1][col] = cost[m - 1][col] + dp[m - 1][col + 1];
	}

	//Fill last col (bottom to top)
	for (int row = m - 2; row >= 0; row--) {
		dp[row][n - 1] = cost[row][n - 1] + dp[row + 1][n - 1];
	}

	//Fill remaining cells
	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			dp[i][j] = min(dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]) + cost[i][j];
		}
	}
	return dp[0][0];

}
//memoization
int mincost_memoization_helper(int i, int j, int m, int n, int**cost, int **dp) {
	if (i >= m || j >= n) return INT_MAX;
	if (i == m - 1 && j == n - 1) return cost[m - 1][n - 1];
	if (dp[i][j] != -1) return dp[i][j];

	int right = mincost_memoization_helper(i, j + 1, m, n, cost, dp);
	int down = mincost_memoization_helper(i + 1, j, m, n, cost, dp);
	int diagnol = mincost_memoization_helper(i + 1, j + 1, m, n, cost, dp);
	int ans = min(right, down, diagnol) + cost[i][j];
	dp[i][j] = ans;
	return ans;
}
int mincost_memoization (int**cost, int m, int n) {
	int **dp = new int*[m];
	for (int i = 0; i < m; i++) {
		dp[i] = new int[n];
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	//dp[i][j] represents cost to go from (i,j) to (m,n)
	return mincost_memoization_helper(0, 0, m, n, cost, dp);
}
//recursive
int minCost_gfg(int **cost, int m, int n)
{
	if (n < 0 || m < 0) return INT_MAX;
	if (m == 0 && n == 0) return cost[m][n];

	return cost[m][n] + min( minCost_gfg(cost, m - 1, n - 1),
	                         minCost_gfg(cost, m - 1, n),
	                         minCost_gfg(cost, m, n - 1) );
}
int mincost(int i, int j, int m, int n, int**cost) {
	if (i >= m || j >= n) return INT_MAX;
	if (i == m - 1 && j == n - 1) return cost[m - 1][n - 1];

	int right = mincost(i, j + 1, m, n, cost);
	int down = mincost(i + 1, j, m, n, cost);
	int diagnol = mincost(i + 1, j + 1, m, n, cost);
	int ans = min(right, down, diagnol);
	return ans + cost[i][j];

}
int main() {
	int m, n;
	cin >> m >> n;
	int **cost = new int*[m];
	for (int i = 0; i < m; i++) {
		cost[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
	cout << mincost_dp(cost, m, n) << endl;
	cout << mincost_memoization(cost, m, n) << endl;
	cout << mincost(0, 0, m, n, cost) << endl;
	cout << minCost_gfg(cost, m - 1, n - 1) << endl;
}
// int main()
// {
// 	int m, n;
// 	cin >> m >> n;
// 	vector<vector<int>> cost(m, vector<int> (n));
// 	// int cost[m][n];
// 	for (int i = 0; i < m; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> cost[i][j];
// 		}
// 	}
// 	cout << mincost(0, 0, m, n, cost) << endl;
// 	for (int i = 0; i < m; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cout << cost[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }