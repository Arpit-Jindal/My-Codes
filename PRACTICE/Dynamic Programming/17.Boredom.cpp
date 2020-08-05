#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int>a)
{
  vector<int> freq(1001, 0);
  for (int i = 0; i < n; i++) {
    freq[a[i]]++;
  }
  vector<int> dp(1001, 0);
  dp[0] = 0;
  dp[1] = freq[1];
  for (int i = 2; i < 1001; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
  }
  return dp[1000];

}
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {cin >> a[i];}
  cout << solve(n, a);
}
