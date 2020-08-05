#include<bits/stdc++.h>
using namespace std;
vector<int> findSubstring(string A, const vector<string> &B) {
	multiset<string> L, temp;
	vector<int> ans;
	for (auto x : B)L.insert(x);
	int total_length = B.size() * B[0].length();
	if (total_length > A.size()) return ans;
	for (int i = 0; i <= A.length() - total_length; i++) {
		int si = i;
		temp = L;
		cout << "i = " << i << endl;
		while (!temp.empty()) {
			string s = "";
			int n = B[0].length();
			while (n--) {
				s += A[i++];
			}
			if (temp.find(s) != temp.end()) {
				cout << s << endl;
				temp.erase(s);
			}
			else {
				break;
			}
		}
		if (temp.empty()) {
			ans.push_back(si);
		}
		i = si;
	}
	return ans;
}

int main() {
	string a = "cacbbcabbacccacacaacacbbaccaabcbcbbcabbacc";
	vector<string> b {"b", "a", "b", "a", "c", "a", "b"};
	vector<int> ans = findSubstring(a, b);
	for (auto x : ans)cout << x << " ";
}