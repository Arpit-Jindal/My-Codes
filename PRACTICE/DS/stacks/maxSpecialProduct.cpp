#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int maxSpecialProduct(vector<int> &A) {
	stack<int> s;
	int n = A.size();

	vector<long long> leftVal(n, 0);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && A[i] >= A[s.top()]) s.pop();
		leftVal[i] = (s.empty()) ? 0 : s.top();
		s.push(i);
	}
	while (!s.empty())s.pop();

	vector<long long> rightVal(n, 0);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && A[s.top()] < A[i]) {
			rightVal[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	long long ans = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		long long x = (leftVal[i] * rightVal[i]);
		if (curr < x)curr = x;
		if (ans < curr)ans = curr;
	}
	return ans % mod;
}
int main() {
	vector<int>A { 5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9 };
	cout << maxSpecialProduct(A);
}