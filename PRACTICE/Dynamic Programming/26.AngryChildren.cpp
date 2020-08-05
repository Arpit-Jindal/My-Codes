#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100001];
void solve(int n, int k) {
  //sorting the array
  sort(A, A + n);

  //maintaining sum array for efficient calculations
  vector<int> sum(n, 0);
  sum[0] = A[0];
  for (int i = 1; i < n; i++)
    sum[i] = sum[i - 1] + A[i];

  //calculating cost for first k elements
  int cost = 0;
  for (int i = 1; i < k; i++)
    cost += i * A[i] - sum[i - 1];

  //updating cost by traversing forward in array
  int mincost = cost;
  for (int i = 1; i < n - k; i++) {
    cost = cost - 2 * (sum[i + k - 2] - sum[i - 1]) + (k - 1) * A[i - 1] + (k - 1) * A[i + k - 1];
    mincost = min(mincost, cost);
  }
  cout << mincost;
}
int32_t main() {
  int N, K; cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  solve(N, K);
  return 0;
}