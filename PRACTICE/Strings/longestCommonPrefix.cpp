#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &A) {
	string ans = "";
	for (int i = 0; i < A[0].length(); i++)
	{
		for (int j = 1; j < A.size(); j++)
			if (i >= A[j].length() || A[j][i] != A[0][i])
				return ans;
		ans += A[0][i];
	}
	return ans;
}
int main()
{
	vector<string> A = {"abcd", "abgf", "abnq"};
	cout << longestCommonPrefix(A);
}