#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
//top down
int dp[101][101][2];
int bitCounts(int n, int k, int first) {
  if (n == 1) {
    if (k == 0) return 1;
    return 0;
  }
  if (k < 0) return 0;
  if (dp[n][k][first] != -1) return dp[n][k][first];
  int ans;
  if (first)
    ans = (bitCounts(n - 1, k - 1, 1) + bitCounts(n - 1, k, 0)) % mod;

  else
    ans = (bitCounts(n - 1, k, 1) + bitCounts(n - 1, k, 0)) % mod;

  dp[n][k][first] = ans;
  return ans;
}
//bottomUp
int bitCounts_bottomUp(int n, int k) {
  int ***dp = new int**[n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = new int*[101];
    for (int j = 0; j <= 100; j++) {
      dp[i][j] = new int[2];
      dp[i][j][0] = 0;
      dp[i][j][1] = 0;
    }
  }

  // dp[101][101][2] = {0};
  dp[1][0][0] = dp[1][0][1] = 1;
  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
      dp[i][j][1] = dp[i - 1][j][0];
      if (j > 0)
        dp[i][j][1] = ( dp[i][j][1] + dp[i - 1][j - 1][1]) % mod;
    }
  }

  return (dp[n][k][0] + dp[n][k][1]) % mod;
}
int32_t main()
{
  int t; cin >> t;
  while (t--) {
    int i, n, k; cin >> i >> n >> k;
    // memset(dp,-1,sizeof(dp));
    // int ans = (bitCounts(n,k,1) + bitCounts(n,k,0))%mod;
    int ans = bitCounts_bottomUp(n, k);
    cout << i << " " << ans << endl;
  }
  return 0;
}
