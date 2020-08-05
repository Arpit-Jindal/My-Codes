#include<bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int> v, int n) {
  int mid;
  int s = 0;
  int e = v.size() - 1;
  int ans = -1;

  while (s <= e) {
    mid = (s + e) / 2;
    if (v[mid] == n) {
      ans = mid;
      e = mid - 1;
    } else if (v[mid] < n)
      s = mid + 1;
    else
      e = mid - 1;
  }
  return ans;
}
int lastOccurence(vector<int> v, int n) {
  int mid;
  int s = 0;
  int e = v.size() - 1;
  int ans = -1;

  while (s <= e) {
    mid = (s + e) / 2;
    if (v[mid] == n) {
      ans = mid;
      s = mid + 1;
    } else if (v[mid] < n)
      s = mid + 1;
    else
      e = mid - 1;
  }
  return ans;
}
int main() {
  vector<int> v{1, 2, 2, 2, 4, 4, 5};
  cout << firstOccurence(v, 6);

}