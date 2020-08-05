#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
void helper(vector<int> A, int i, vector<int> v) {
	if (i == A.size()) {
		sort(v.begin(),v.end()); //or just sort A in main()
		ans.push_back(v);
		return;
	}
	v.push_back(A[i]);
	helper(A, i + 1, v);
	v.pop_back();
	helper(A, i + 1, v);
}
int main() {
	vector<int> A{5, 2, 3, 4};
	vector<int> v;
	helper(A, 0, v);
	sort(ans.begin(),ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}