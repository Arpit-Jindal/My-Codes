#include<bits/stdc++.h>
using namespace std;
int value(char r) {
	if (r == 'I') return 1;
	if (r == 'V') return 5;
	if (r == 'X') return 10;
	if (r == 'L') return 50;
	if (r == 'C') return 100;
	if (r == 'D') return 500;
	if (r == 'M') return 1000;
	return -1;
}
int romanToInt(string A) {
	int ans = 0;
	int n = A.length();

	for (int i = 0; i < n; i++) 
    {
        if(i<n-1 && value(A[i])<value(A[i+1])) 
            ans -= value(A[i]);
        else ans += value(A[i]);
    }
	return ans;
}

int main()
{
	cout << romanToInt("MMMDCCLX");
}