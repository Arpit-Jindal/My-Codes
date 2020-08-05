#include<bits/stdc++.h>
using namespace std;
//topDown
int editDistance_topDown(string s1, string s2, int n, int m, vector<vector<int>> &dp) {
  if (m == 0) return n;
  if (n == 0) return m;
  if (dp[n][m] != -1)return dp[n][m];
  int ans;
  if (s1[n - 1] == s2[m - 1]) {
    ans = editDistance_topDown(s1, s2, n - 1, m - 1, dp);
  } else {
    int op1 = editDistance_topDown(s1, s2, n - 1, m, dp);
    int op2 = editDistance_topDown(s1, s2, n, m - 1, dp);
    int op3 = editDistance_topDown(s1, s2, n - 1, m - 1, dp);
    ans = min(op1, min(op2, op3)) + 1;
  }
  dp[n][m] = ans;
  return ans;
}
//bottomUp
int editDistance_bottomUp(string s1, string s2) {
  int n = s1.size();
  int m = s2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int i = 0; i <= m; i++) dp[0][i] = i;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
    }
  }
  return dp[n][m];
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size();
  int m = s2.size();

  //topDown
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  cout << editDistance_topDown(s1, s2, n, m, dp) << "\n";
  //bottomUp
  cout << editDistance_bottomUp(s1, s2) << endl;
}