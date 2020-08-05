#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	int sum = 0;
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		sum += v[i];
	}
	ans.push_back(sum);
	for (int i = k; i < v.size(); i++) {
		sum += v[i] - v[i - k];
		ans.push_back(sum);
	}
	for (auto x : ans)cout << x << " ";
}