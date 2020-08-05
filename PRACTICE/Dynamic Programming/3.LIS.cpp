#include<bits/stdc++.h>
using namespace std;
//Brute Force - generate all subsequence and check for the largest increasing one - O(2^n)
void rec(int* arr, int n, vector<vector<int>> &output) {
	if (n == 0) {
		vector<int> v;
		output.push_back(v);
		return;
	}
	rec(arr, n - 1, output);
	int s = output.size();
	for (int i = 0; i < s; i++) {
		output.push_back(output[i]);
		output[i].push_back(arr[n - 1]);
	}
}
int LIS_bruteForce(int* arr, int n) {
	vector<vector<int>> output;
	rec(arr, n, output);
	int ans = 0;
	for (int i = 0; i < output.size(); i++) {
		int s = output[i].size();
		for (int j = 1; j < s; j++) {
			if (output[i][j] < output[i][j - 1])
				break;
			if (j == s - 1)
				ans = max(ans, s);
		}
	}
	return ans;
}
//DP - O(n^2)
int LIS(int *arr, int n) {
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
	}
	//return max of array - return *max_element(dp.begin(),dp.end());
	int best = 0;
	for (int i = 0; i < n; i++) best = max(best, dp[i]);
	return best;
}
int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << LIS(arr, n) << endl;
	cout << LIS_bruteForce(arr, n);
}