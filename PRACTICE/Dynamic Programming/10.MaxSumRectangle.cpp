#include<bits/stdc++.h>
using namespace std;
int kadan(vector<int> sum, int n) {
	int curr_max = sum[0];
	int maxVal = sum[0];
	for (int i = 1; i < n; i++) {
		curr_max = max(sum[i], curr_max + sum[i]);
		maxVal = max(maxVal, curr_max);
	}
	return maxVal;
}
int maxSum(vector<vector<int>> &grid, int n, int m) {
	vector<int> sum(n, 0);
	int ans = -1e9;
	for (int l = 0; l < m; l++) {
		fill(sum.begin(), sum.end(), 0);
		for (int r = l; r < m; r++) {

			//updating sum array
			for (int i = 0; i < n; i++)
				sum[i] += grid[i][r];

			//applying kadan's
			ans = max(ans, kadan(sum, n));
			// cout << ans << endl;
		}
	}
	return ans;
}
int main() {
	int r, c; cin >> r >> c;
	vector<vector<int>> grid (r, vector<int>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> grid[i][j];
	cout << maxSum(grid, r, c);
}