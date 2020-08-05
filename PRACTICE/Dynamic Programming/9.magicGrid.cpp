#include<bits/stdc++.h>
using namespace std;
void printVector(vector<vector<int>> v) {
	for (auto i : v) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}
int minHealth(vector<vector<int>> &grid, int si, int sj, int ei, int ej, vector<vector<int>> &dp) {
	if (si == ei && sj == ej) return 1;
	if (dp[si][sj] != -1) return dp[si][sj];

	int ans1 = 1e9, ans2 = 1e9;
	if (si + 1 <= ei)
		ans1 = minHealth(grid, si + 1, sj, ei, ej, dp) - grid[si + 1][sj];
	if (sj + 1 <= ej)
		ans2 = minHealth(grid, si, sj + 1, ei, ej, dp) - grid[si][sj + 1];

	int ans = min(ans1, ans2);
	if (ans < 1) ans = 1;
	dp[si][sj] = ans;
	return ans;
}
//bottom up
int minHealth_bottomUp(vector<vector<int>> &grid) {
	int r = grid.size();
	int c = grid[0].size();
	if (r == 1 && c == 1) return 1;
	vector<vector<int>> dp (r, vector<int>(c));
	//Base values
	dp[r - 1][c - 1] = dp[r - 2][c - 1] = dp[r - 1][c - 2] = 1;
	for (int j = c - 2; j >= 0; j--) {
		dp[r - 1][j] = dp[r - 1][j + 1] - grid[r - 1][j + 1];
		if (dp[r - 1][j] < 1) dp[r - 1][j] = 1 ;
	}
	for (int i = r - 2; i >= 0; i--) {
		dp[i][c - 1] = dp[i + 1][c - 1] - grid[i + 1][c - 1];
		if (dp[i][c - 1] < 1) dp[i][c - 1] = 1;
	}

	//Main code
	for (int i = r - 2; i >= 0; i--) {
		for (int j = c - 2; j >= 0; j--) {
			int a = dp[i + 1][j] - grid[i + 1][j];
			int b = dp[i][j + 1] - grid[i][j + 1];
			dp[i][j] = min(a, b);
			if (dp[i][j] < 1) dp[i][j] = 1;
		}
	}
	// printVector(dp);
	return dp[0][0];
}
int main() {
	int t; cin >> t;
	while (t--) {
		int r, c; cin >> r >> c;
		vector<vector<int>> grid (r, vector<int>(c));
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> grid[i][j];
		vector<vector<int>> dp (r, vector<int>(c, -1));
		cout << minHealth(grid, 0, 0, r - 1, c - 1, dp) << " " ;
		// printVector(dp);
		cout << minHealth_bottomUp(grid) << endl;
	}
}
/* input
3

2 3
0 1 -3
1 -2 0

2 3
0 -2 -1
-1 2 0

3 4
0 -2 -3 1
-1 4 -8 -1
1 -2 -3 0
*/