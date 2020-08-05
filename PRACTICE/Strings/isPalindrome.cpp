#include<bits/stdc++.h>
using namespace std;
int isPalindrome(string A) {
	int i = 0;
	int j = A.length() - 1;
	while (i < j) {
		while (i < j && !isalnum(A[i])) i++;
		while (i < j && !isalnum(A[j])) j--;
		if (tolower(A[i]) != tolower(A[j])) return 0;
		i++; j--;
	}
	return 1;
}

int main()
{
	if (a > b) {
		while (i < A.length()) {
			res = A[i] + c;
			if (res > 1) {
				res = res % 2;
				c = 1;
			}
			ans += res;
			i++;
		}
	}
	cout << isPalindrome("race a car");
}