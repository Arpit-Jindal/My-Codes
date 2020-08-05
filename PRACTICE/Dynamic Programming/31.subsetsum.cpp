#include<bits/stdc++.h>
using namespace std;

int t[100][100];
//topDown
int subsetSum(int arr[], int n, int sum) {
	if (sum == 0)return 1;
	if (n == 0) return 0;
	if (t[n][sum] != -1)return t[n][sum];
	if (arr[n - 1] > sum) return t[n][sum] = subsetSum(arr, n - 1, sum);
	else return t[n][sum] = max(subsetSum(arr, n - 1, sum), subsetSum(arr, n - 1, sum - arr[n - 1]));
}
//bottom Up
int subsetSum2(int arr[], int n, int sum) {
	int dp[n + 1][sum + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j == 0)dp[i][j] = 1;
			else if (i == 0)dp[i][j] = 0;
			else if (arr[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j - arr[i - 1]] , dp[i - 1][j]);
		}
	}
	return dp[n][sum];
}
int main() {
	int n = 5;
	int arr[5] = {3, 2, 5, 6, 1};
	int sum = 10;
	memset(t, -1, sizeof t);
	cout << subsetSum(arr, n, sum) << endl;
	cout << subsetSum2(arr, n, sum) << endl;
}