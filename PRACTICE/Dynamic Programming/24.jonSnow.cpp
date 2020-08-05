#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, k, x; cin >> n >> k >> x;
  vector<int> input(n);
  int count[1024] = {0};
  for (int i = 0; i < n; i++) {
    cin >> input[i];
    count[input[i]]++;
  }
  int temp[1024] = {0};
  long long flag = 0;
  for (int c = 0; c < k; c++) {

    for (int i = 0; i < 1024; i++) {

      if (count[i] > 0) {

        int retain;
        if (flag & 1) retain = count[i] - count[i] / 2;
        else retain = count[i] - ceil((double)count[i] / 2);

        temp[i] += retain;

        int newval = i ^ x;
        temp[newval] += count[i] - retain;

        flag += count[i];
      }
    }

    copy(begin(temp), end(temp), begin(count));
    memset(temp, 0, sizeof(temp));
    flag = 0;
  }
  for (int i = 1023; i >= 0; i--) {
    if (count[i] > 0) {
      cout << i << " ";
      break;
    }
  }
  for (int i = 0; i < 1024; i++) {
    if (count[i] > 0) {
      cout << i;
      break;
    }
  }
  return 0;
}