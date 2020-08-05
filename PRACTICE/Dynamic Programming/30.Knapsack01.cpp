#include<bits/stdc++.h>
using namespace std;

int t[100][100];
//topDown
int knapsack(int wt[], int val[], int n, int W) {
	if (n == 0 || W == 0)return 0;
	if (t[n][W] != -1)return t[n][W];
	if (wt[n - 1] > W) return t[n][W] = knapsack(wt, val, n - 1, W);
	else return t[n][W] = max(knapsack(wt, val, n - 1, W), val[n - 1] + knapsack(wt, val, n - 1, W - wt[n - 1]));
}
//bottom Up
int knapsack2(int wt[], int val[], int n, int W) {
	int dp[n + 1][W + 1];
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (wt[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]] , dp[i - 1][j]);
		}
	}
	return dp[n][W];
}
int main() {
	int n = 5;
	int wt[5] = {3, 2, 5, 6, 1};
	int val[5] = {7, 9, 3, 1, 8};
	int W = 10;
	memset(t, -1, sizeof t);
	cout << knapsack(wt, val, n, W) << endl;
	cout << knapsack2(wt, val, n, W) << endl;
}