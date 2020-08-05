#include<bits/stdc++.h>
using namespace std;
//O(n^2) time and O(n^2) space
vector<vector<int> > solve(int n) {
	vector<int> v;
	vector<vector<int>> ans;

	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)v.push_back(1);
			else {
				v.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
			}
		}
		ans.push_back(v);
	}
	return ans;
}

//O(n^2) time and O(1) space
vector<vector<int> > solve(int n) {
	vector<int> v;
	vector<vector<int>> ans;

	for (int i = 0; i < n; i++) {
		v.clear();
		int c = 1;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) v.push_back(1);
			else {
				c = c * (i - j + 1) / j;
				v.push_back(c);
			}
		}
		ans.push_back(v);
	}

	//OR

	// for (int line = 1; line <= n; line++) {
	// 	int C = 1;
	// 	v.clear();
	// 	for (int i = 1; i <= line; i++) {
	// 		v.push_back(C);
	// 		C = C * (line - i) / i;
	// 	}
	// 	ans.push_back(v);
	// }

	return ans;
}
//print ith row
vector<int> Solution::getRow(int i) {
	vector<int> v;
	int c = 1;
	for (int j = 0; j <= i; j++) {
		if (j == 0 || j == i) v.push_back(1);
		else {
			c = c * (i - j + 1) / j;
			v.push_back(c);
		}
	}
	return v;
}

int main()
{

}