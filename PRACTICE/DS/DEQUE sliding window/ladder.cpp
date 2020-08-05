/*
Given a ladder containing N-steps such that from every step you can take a jump of min of size{1,2,3,...,k}.
Find no. of ways to reach to the top.
*/
#include<bits/stc++.h>
using namespace std;

int main()
{
	int n = 10, k = 3;
	vector<int> v(n + 1);
	v[0] = 0; v[1] = 1; v[2] = 2;
	for (int i = 3; i <= n; i++) {
		v[i] = 2 * v[i - 1] - v[i - k];
	}
	//v[n] -> answer
}