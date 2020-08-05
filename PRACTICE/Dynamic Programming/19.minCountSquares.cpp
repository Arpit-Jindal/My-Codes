#include<bits/stdc++.h>
using namespace std;
//top down
vector<int> dp(1001, -1);
int minCount(int n)
{
	if (n == 1)return 1;
	if (n == 0) return 0;
	if (dp[n] != -1)return dp[n];
	int ans = 1e9;
	for (int i = 1; i * i <= n; i++) {
		int a = minCount(n - i * i) + 1;
		ans = min(a, ans);
	}
	dp[n] = ans;
	return ans;
}
//bottomUp
int minCount_bottomUp(int n)
{
	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int z = 1; z * z <= i; z++) {
			dp[i] = min(dp[i], dp[i - z * z] + 1);
		}
	}
	return dp[n];
}
int main() {

}