#include<bits/stdc++.h>
using namespace std;
//O(n2)
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
	sort(A.begin(), A.end());
	unordered_map<int, vector<pair<int, int>>>m;
	map<vector<int>, int> dup;
	vector<int> v(4);
	vector<vector<int>> ans;
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			m[A[i] + A[j]].push_back({i, j});
		}
	}
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			int sum = B - A[i] - A[j];
			if (m.find(sum) != m.end()) {
				for (auto x : m[sum]) {
					if (x.first != i && x.first != j && x.second != i && x.second != j) {
						v[0] = A[i]; v[1] = A[j]; v[2] = A[x.first]; v[3] = A[x.second];
						sort(v.begin(), v.end());
						if (dup[v] == 0) {
							ans.push_back(v);
						}
						dup[v]++;
					}
				}
			}
		}
	}
	return ans;
}


//O(n3)
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
	vector<vector<int> >sol;
	if (A.size() < 4) return sol;
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size() - 3; i++)
	{
		if (i > 0 && A[i - 1] == A[i])continue;
		for (int j = i + 1; j < A.size() - 2; j++)
		{
			if (j > i + 1 && A[j - 1] == A[j])continue;
			for (int k = j + 1, l = A.size() - 1; k < l;)
			{
				long long sum = 0LL + A[i] + A[j] + A[k] + A[l];
				if (sum == B)
				{
					vector<int> temp;
					temp.push_back(A[i]);
					temp.push_back(A[j]);
					temp.push_back(A[k]);
					temp.push_back(A[l]);
					sol.push_back(temp);
					k++;
					while (k < l && A[k] == A[k - 1]) k++;
				}
				else if (sum < B) k++;
				else l--;
			}
		}
	}
	return sol;
}
int main() {
	vector<int> v{ 8, -14, 40, -17, 26, 4, 33, -4, -10, -7, 21, 25, -10, -16, 28, 17};

}