#include<bits/stdc++.h>
using namespace std;
int maxLoot(vector<int>&v, int n) {
	if (n == 0) return 0;
	if (n == 1)return v[0];

	//O(n) space
	vector<int> dp(n);
	dp[0] = v[0];
	dp[1] = max(v[0], v[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
	}
	return dp[n - 1];

	//O(1) space
	int v1 = v[0];
	int v2 = max(v[0], v[1]);
	int ans = -1e9;
	for (int i = 2; i < n; i++) {
		ans = max(v1 + v[i], v2);
		v1 = v2;
		v2 = ans;
	}
	return ans;
}
int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {cin >> v[i];}
	cout << maxLoot(v, n);
}