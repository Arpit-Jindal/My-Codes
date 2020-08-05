//Max sub square of all 0s in binary matrix
#include<bits/stdc++.h>
using namespace std;
int maxSubSquare(vector<vector<int>> &input) {
	int n = input.size();
	int m = input[0].size();

	vector<vector<int>> dp (n, vector<int>(m));

	//Base Values - replacing 0&1 bcz we want ans for 0
	for (int j = 0; j < m; j++)
		dp[0][j] = 1 - input[0][j];

	for (int i = 0; i < n; i++)
		dp[i][0] = 1 - input[i][0];

	int ans = -1e9;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			//only when 0 encountered
			if (1 - input[i][j]) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	return ans;
}
int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> input (n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> input[i][j];

	cout << maxSubSquare(input);
}