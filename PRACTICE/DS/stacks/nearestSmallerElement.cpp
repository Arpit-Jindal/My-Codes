#include<bits/stdc++.h>
using namespace std;

vector<int> PrevSmaller(vector<int> &v) {
	int n = A.size();
	vector<int> ans(n, -1);
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && A[i] <= A[s.top()]) {
			s.pop();
		}
		ans[i] = (s.empty()) ? -1 : A[s.top()];
		s.push(i);
	}
	return ans;
}
int main()
{

}