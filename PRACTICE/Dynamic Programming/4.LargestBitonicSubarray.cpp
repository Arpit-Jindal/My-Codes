#include<bits/stdc++.h>
using namespace std;
int bitonic(vector<int> arr, int n) {
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
	}

	vector<int> dp2(n);
	dp2[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[i])
				dp2[i] = max(dp2[i], dp2[j] + 1);
	}

	for (int i = 0; i < n; i++)
		dp[i] = dp[i] + dp2[i] - 1;

	//return max of array
	int best = 0;
	for (int i = 0; i < n; i++) best = max(best, dp[i]);
	return best;
}
int main() {
	int n; cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];
	cout << bitonic(input, n);
}