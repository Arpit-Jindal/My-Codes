#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[501][101] = {0};
int LIScoPrime(vector<int> arr, int n) {
  for (int i = 1; i < n; i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] < arr[i])
      {
        for (int k = 1; k <= 100; k++)
        {
          int x = __gcd(arr[i], k);
          dp[i][x] = (dp[i][x] + dp[j][k]) % mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = (ans + dp[i][1]) % mod;
  return ans;
}
int main()
{
  int n; cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    dp[i][arr[i]] = 1;
  }
  cout << LIScoPrime(arr, n);
  return 0;
}

