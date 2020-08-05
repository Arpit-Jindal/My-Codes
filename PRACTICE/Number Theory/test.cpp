#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>one, vector<int>two, int k) {
  // Hint: keys are one's indices, values are two's indices
  vector<int> idxMap(one.size());
  for (int i = 0; i < k; i++) {
    int min = 2e9;
    int oneIdx = -1;
    int twoIdx = -1;

    for (int j = 0; j < one.size(); j++) {
      if (idxMap[j] == two.size())
        continue;


      if (one[j] + two[idxMap[j]] < min) {
        min = one[j] + two[idxMap[j]];
        oneIdx = j;
        twoIdx = idxMap[j];
      }

    }
    idxMap[oneIdx]++;
    cout << one[oneIdx] << " " << two[twoIdx];
    cout << ", ";
  }
}
int main() {
  vector<int> one{1, 7, 11};
  vector<int> two{2, 4, 6};
  solve(one, two, 3);
}