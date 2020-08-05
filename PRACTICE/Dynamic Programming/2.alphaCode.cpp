#include<bits/stdc++.h>
using namespace std;
#define int long long
#define m 1000000007
int num_codes(int *arr, int n) {
	if (n == 0 || n == 1) return 1;
	int ans = num_codes(arr, n - 1);
	if (arr[n - 2] * 10 + arr[n - 1] <= 26) {
		ans += num_codes(arr, n - 2);
	}
	return ans;
}
int num_codes_topdown(int *arr, int n, vector<int> dp) {
	if (n == 0 || n == 1) return 1;
	if (dp[n] != -1)return dp[n];
	int ans = num_codes(arr, n - 1);
	if (arr[n - 2] * 10 + arr[n - 1] <= 26) {
		ans += num_codes(arr, n - 2);
	}
	dp[n] = ans;
	return ans;
}
int num_codes_bottomup(int* arr, int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	if (arr[0] != 0) dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (arr[i - 1] != 0)
			dp[i] = dp[i - 1];

		if (arr[i - 2] != 0) {
			int val = arr[i - 2] * 10 + arr[i - 1];
			if (val > 0 && val <= 26)
				dp[i] = (dp[i] + dp[i - 2]) % m;
		}
	}
	return dp[n];
}
int32_t main() {
	while (1) {
		string s;
		cin >> s;
		if (s == "0") break;
		int n = s.size();
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = s[i] - '0';
		}
		// cout << num_codes(arr, n) << endl;
		vector<int> dp(n + 1, -1);
		cout << num_codes_topdown(arr, n, dp) << endl;
		// cout << num_codes_bottomup(arr, n) << endl;
		delete[] arr;
	}
}