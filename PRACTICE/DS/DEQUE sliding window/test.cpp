#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector <int>& a, int mid) {
  map <int, int> m;
  vector <int> v(2);
  int  k = 0;
  for (int i = 0 ; i < mid ; i++)
    m[a[i]]++;
  if (m.size() == 1) return true;
  if (m.size() <= 2)
  {
    for (auto i : m) v[k++] = i.first;
    if (abs(v[0] - v[1]) <= 1) return true;
  }

  for (int i = mid ; i < a.size() ; i++)
  {
    k = 0;
    m[a[i - mid]]--;
    if (m[a[i - mid]] == 0) m.erase(a[i - mid]);
    m[a[i]]++;
    if (m.size() == 1) return true;
    if (m.size() <= 2) {
      for (auto i : m) v[k++] = i.first;
      if (abs(v[0] - v[1]) <= 1) return true;
    }
  }
  return false;
}

int32_t main() {
  int n; cin >> n; vector <int> a(n); for (int i = 0 ; i < n ; i++) cin >> a[i];
  int ans = 1;
  for (int l = 1, r = n, mid = (l + r) / 2 ; l <= r ; mid = (l + r) / 2) {
    if (check(a, mid)) {ans = mid; l = mid + 1;}
    else r = mid - 1;
  }
  cout << ans;
}