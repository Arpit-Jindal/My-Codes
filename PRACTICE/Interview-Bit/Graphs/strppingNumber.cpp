#include<bits/stdc++.h>
using namespace std;
//DFS
void dfs(int A, int B, vector<int> &ans, int i) {
	if (i > B) return;
	if (i >= A) ans.push_back(i);
	int lastd = i % 10;
	if (lastd > 0) dfs(A, B, ans, i * 10 + lastd - 1);
	if (lastd < 9) dfs(A, B, ans, i * 10 + lastd + 1);
}
vector<int> stepnum(int A, int B) {
	vector<int> ans;
	if (A <= 0) ans.push_back(0);
	for (int i = 1; i <= 9; i++)
		dfs(A, B, ans, i);

	sort(ans.begin(), ans.end());
	return ans;
}

//BFS
vector<int> stepnum(int A, int B) {
	vector<int> ans;
	if (A <= 0) ans.push_back(0);

	queue<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});

	while (nums.front() <= B) {
		int i = nums.front();
		nums.pop();
		if (i >= A) ans.push_back(i);

		int lastd = i % 10;
		if (lastd > 0) nums.push(i * 10 + (lastd - 1));
		if (lastd < 9) nums.push(i * 10 + (lastd + 1));
	}

	return ans;
}
int main() {
	int n; cin >> n;
	cout << isSteppingNumber(n);
}