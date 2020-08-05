//Print longest substring without repeating characters
#include<bits/stdc++.h>
using namespace std;
string longestSubstring(string str) {
	int curr_len = 1, max_len = 1;
	int st = 0;
	int start = 0;
	unordered_map<char, int> pos;
	pos[str[0]] = 0;
	int i = 1;
	for (; i < str.length(); i++) {
		if (pos.find(str[i]) == pos.end()) {
			pos[str[i]] = i;
		}
		else {
			if (pos[str[i]] >= st) {
				curr_len = i - st;
				if (max_len < curr_len) {
					max_len = curr_len;
					start = st;
				}
				st = pos[str[i]] + 1;
			}
			pos[str[i]] = i;
		}
	}

	curr_len = i - st;
	if (max_len < curr_len) {
		max_len = curr_len;
		start = st;
	}
	return str.substr(start, max_len);
}
int main() {

}