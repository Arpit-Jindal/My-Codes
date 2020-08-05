#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m; cin >> n >> m;
  vector<int> v(n + 1, 0);
  int start[n + 1] = {0};
  int end[n + 1] = {0};

  for (int i = 0; i < m; ++i) {
    int l, r; cin >> l >> r;
    ++start[l];
    ++end[r];
  }

  v[1] = start[1];
  for (int i = 2; i <= n; ++i)
    v[i] = start[i] + v[i - 1] - end[i - 1];

  vector<int> count(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    count[v[i]]++;
  }

  vector<int> atleast(n + 1, 0);
  atleast[n] = count[n];
  for (int i = n - 1; i >= 1; i--) {
    atleast[i] = atleast[i + 1] + count[i];
  }

  // sort(v.begin(), v.end());
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    cout << atleast[x] << endl;
    // cout<<(v.end() - lower_bound(v.begin(),v.end(),x))<<endl;
  }
  return 0;
}