#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void helper(int pos, int n, int open, int close) {
	static char str[100];
	if (close == n) {
		string s = "";
		for (int i = 0; i < pos; i++) {
			s += str[i];
		}
		ans.push_back(s);
		return;
	}
	else {
		if (open < n) {
			str[pos] = '(';
			helper(pos + 1, n, open + 1, close);
		}
		if (open > close) {
			str[pos] = ')';
			helper(pos + 1, n, open, close + 1);
		}
	}

}
int main()
{
	int A = 2;
	ans.clear();
	helper(0, A, 0, 0);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].length(); j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}
