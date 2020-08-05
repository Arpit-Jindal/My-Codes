#include<bits/stdc++.h>
using namespace std;
void rec(int* arr, int n, vector<vector<int>> &output) {
	if (n == 0) {
		vector<int> v;
		output.push_back(v);
		return;
	}
	rec(arr, n - 1, output);
	int s = output.size();
	for (int i = 0; i < s; i++) {
		output.push_back(output[i]);
		output[i].push_back(arr[n - 1]);
	}
}
int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<vector<int>> output;
	rec(arr, n, output);
	for (auto i : output) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}