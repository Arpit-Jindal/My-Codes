//What is the length of the longest substring without repeated characters
#include <iostream>
#include<cstring>
using namespace std;
int lengthOfLongestSubstring(string s)
{
  int i = 0, ans = 0, curr = 0;
  unordered_map<char, int> m;
  for (int j = 0; j < s.length(); j++)
  {
    m[s[j]]++;
    while (m[s[j]] > 1) m[s[i++]]--;
    curr = j - i + 1;
    ans = max(ans, curr);
  }
  return ans;
}
int main() {

}
