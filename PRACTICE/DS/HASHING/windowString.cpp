#include<bits/stdc++.h>
using namespace std;
string minWindow(string A, string B) {
	int l1 = A.length();
	int l2 = B.length();
	int a[256] = {0};
	int b[256] = {0};
	for (int i = 0; i < l2; i++)
		b[B[i]]++;
	int start = 0, count = 0, start_index = -1, minlength = INT_MAX;
	for (int j = 0; j < l1; j++)
	{
		a[A[j]]++;
		if (b[A[j]] != 0 && a[A[j]] <= b[A[j]]) {
			count++;
		}
		if (count == l2)
		{
			while (a[A[start]] > b[A[start]])
			{
				a[A[start]]--;
				start++;
			}
			if (minlength > (j - start + 1))
			{
				minlength = j - start + 1;
				start_index = start;
			}
		}
	}
	if (start_index == -1)return "";
	return A.substr(start_index, minlength);
}

int main()
{
	string S = "ADOBECODEBANC";
	string T = "ABC";
	cout << minWindow(S, T);
}