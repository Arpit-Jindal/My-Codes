#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m; cin >> n >> m;
  vector<vector<int>> input(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> input[i][j];
    }
  }

  //making dp 2d array
  vector<vector<int>> dp(n, vector<int>(m, 0));
  vector<int> ans(n);
  ans[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (input[i][j] >= input[i - 1][j]) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        dp[i][j] = i;
      }
    }
    ans[i] = *min_element(dp[i].begin(), dp[i].end());
  }
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    --l; --r;
    if (l >= ans[r])cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
