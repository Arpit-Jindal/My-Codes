#include<bits/stdc++.h>
using namespace std;
int minChocolates(vector<int> a, int n) {
	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++)
		if (a[i - 1] < a[i])
			dp[i] = dp[i - 1] + 1;

	for (int i = n - 2; i >= 0; i--)
		if (a[i + 1] < a[i])
			dp[i] = max(dp[i], dp[i + 1] + 1);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += dp[i];
	return ans;
}
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {cin >> a[i];}
	cout << minChocolates(a, n);
}