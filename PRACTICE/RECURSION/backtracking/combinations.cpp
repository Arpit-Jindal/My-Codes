#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
void helper(int n, int k, int i, vector<int> v) {
	if (v.size() == k ) {
		ans.push_back(v);
		return;
	}
	for (int j = i; j <= n; j++) {
		v.push_back(j);
		helper(n, k, j + 1, v);
		v.pop_back();
	}
}
int main() {
	vector<int> v;
	helper(3, 2, 1, v);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}
// void comb(int A, int B, int start, int depth, vector<vector > &v, vector &arr)
// {	if (depth == 0)
// 	{	v.push_back(arr);
// 		return ;
// 	}
// 	for (int i = start; i < A + 1; i++)
// 	{	arr.push_back(i);
// 		comb(A, B, i + 1, depth - 1, v, arr);
// 		arr.pop_back();
// 	}
// }
// vector<vector > combine(int A, int B) {
// 	vector<vector > v;
// 	vector arr;
// 	comb(A, B, 1, B, v, arr);
// 	return v;
// }