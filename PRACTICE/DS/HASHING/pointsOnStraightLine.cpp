#include<bits/stdc++.h>
using namespace std;
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
	int n = A.size();
	if (n <= 2) return n;
	unordered_map<double, int> m;
	int sol = 2;
	for (int i = 0; i < n; i++)
	{
		int dup = 0, ver = 0, curr = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] == A[j])
			{
				if (B[i] == B[j]) dup++;
				else ver++;
			}
			else
			{
				double x = A[j] - A[i];
				double y = B[j] - B[i];
				double slope = y / x;
				m[slope]++;
				curr = max(curr, m[slope]);
			}
		}
		m.clear();
		sol = max(sol, curr + dup + 1);
		sol = max(sol, ver + dup + 1);
	}
	return sol;
}
int main()
{

}