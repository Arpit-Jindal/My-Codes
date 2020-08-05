#include<bits/stdc++.h>
using namespace std;
string convert(string A, int B) {
	string ans = "";
	if (B == 1) return A;
	for (int i = 0; i < B; i++)
	{
		for (int j = i; j < A.size(); j += 2 * (B - 1))
		{
			ans += A[j];
			if (i != 0 && i != B - 1) 
			{
				int t = j + 2 * (B - 1 - i);
				if (t < A.size()) ans += A[t];
			}
		}
	}
	return ans;
}
int main()
{
	
}