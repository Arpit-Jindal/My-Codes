#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void helper1(vector<int> A, int i, vector<int> &v) {
	if (i == A.size()) {
		v.clear();
		for (int j = 0; j < A.size(); j++) {
			v.push_back(A[j]);
		}
		ans.push_back(v);
		return;
	}
	for (int j = i; j < A.size(); j++) {
		swap(A[i], A[j]);
		helper1(A, i + 1, v);
		//Backtracking step not required because vectors are not passed by reference unless we specify
	}
}
//2nd approach
void helper2(vector<int> A, int i, vector<int> &v) {
	if (i == A.size()) {
		ans.push_back(v);
		return;
	}
	for (int j = i; j < A.size(); j++) {
		swap(A[i], A[j]);
		v.push_back(A[i]);
		helper2(A, i + 1, v);
		v.pop_back();
	}
}
//3rd Approach
void helper3(vector<int> A, int i, vector<int> &v) {
	if (i == A.size()) {
		v.clear();
		for (int j = 0; j < A.size(); j++) {
			v.push_back(A[j]);
		}
		ans.push_back(v);
		return;
	}
	for (int j = i; j < A.size(); j++) {
		swap(A[i], A[j]);
		helper3(A, i + 1, v);
		swap(A[i], A[j]); //Here we have written the backtracking step
	}
}
int main()
{
	ans.clear();
	vector<int> A{1, 2, 3};
	vector<int> v;
	helper3(A, 0, v);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}