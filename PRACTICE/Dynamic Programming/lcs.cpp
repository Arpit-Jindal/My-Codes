#include<bits/stdc++.h>
using namespace std;
//dp
int lcs_dp(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **dp = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}
	//dp[i][j] = LCS of s(len = i) and t(len = j)

	//Fill first row and first col with 0 value bcz if one of the string length is 0 then the lcs is also 0
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= n; j++) {
		dp[0][j] = 0;
	}
	//Fill rest of the table
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			//if (s[m-i] == t[n-j]){}
			if (s[i-1] == t[j-1]) {
				dp[i][j] kl= dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				// dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
			}
		}
	}
	return dp[m][n];
}
//memoisation
int lcs_memoization_helper(string s, string t, int**dp) {
	int m = s.size();
	int n = t.size();
	//Base Case
	if (m == 0 || n == 0) {
		return 0;
	}
	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	//Recursive case
	int ans;
	if (s[0] == t[0]) {
		ans = 1 + lcs_memoization_helper(s.substr(1), t.substr(1), dp);
	}
	else {
		int a = lcs_memoization_helper(s, t.substr(1), dp);
		int b = lcs_memoization_helper(s.substr(1), t, dp);
		ans = max(a, b);
	}
	dp[m][n] = ans;
	return ans;

}
int lcs_memoization(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **dp = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	//dp[i][j] = LCS of s(len = i) and t(len = j)
	return lcs_memoization_helper(s, t, dp);
}

//recursive
int lcs(string s, string t) {
	//Base Case
	if (s.size() == 0 || t.size() == 0) {
		return 0;
	}
	//Recursive case
	if (s[0] == t[0]) {
		return 1 + lcs(s.substr(1), t.substr(1));
	}
	int a = lcs(s, t.substr(1));
	int b = lcs(s.substr(1), t);
	// int c = lcs(s.substr(1), t.substr(1));  //already handled in a & b
	return max(a, b);
}
int main()
{
	string s, t;
	cin >> s >> t;
	cout << lcs_dp(s, t) << endl;
	cout << lcs_memoization(s, t) << endl;
	// cout << lcs(s, t) << endl;
}