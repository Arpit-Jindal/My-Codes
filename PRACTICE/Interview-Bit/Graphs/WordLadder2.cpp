#include<bits/stdc++.h>
using namespace std;
void printVector(vector<vector<string>> ans) {
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << "->";
    }
    cout << endl;
  }
}
vector<vector<string>> findLadders(string start, string target, vector<string> &d) {
  vector<vector<string>> ans;
  queue<vector<string>> q;
  q.push({start});
  if (start == target) {
    ans.push_back({start});
    return ans;
  }
  unordered_set<string>dict;
  for (int i = 0; i < d.size(); i++) {
    dict.insert(d[i]);
  }
  dict.insert(target);
  int min_level = INT_MAX;
  while (!q.empty()) {
    vector<string> path = q.front(); q.pop();
    if (path.size() > min_level)
      break;
    string last = path.back();
    for (int pos = 0; pos < last.length(); pos++) {
      string newLast = last;
      for (char i = 'a'; i <= 'z'; i++) {
        newLast[pos] = i;
        if (dict.find(newLast) != dict.end()) {
          dict.erase(last);
          vector<string> newpath = path;
          newpath.push_back(newLast);
          if (newLast == target) {
            dict.insert(newLast);
            ans.push_back(newpath);
            min_level = path.size();
          }
          else {
            q.push(newpath);
          }
        }
      }
    }
  }
  return ans;
}
int main() {
  string a = "hit";
  string b = "cog";
  vector<string> c = {"hot", "dot", "log", "lot", "dog"};
  vector<vector<string>> ans = findLadders(a, b, c);
  printVector(ans);
}