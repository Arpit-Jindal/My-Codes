#include<bits/stdc++.h>
using namespace std;
string addBinary(string A, string B) {
	string ans = "";
	int i = A.size() - 1, j = B.size() - 1;
	int s = 0;
	while (i >= 0 || j >= 0 || s == 1) {
		if (i >= 0) s += A[i] - '0';
		if (j >= 0) s += B[j] - '0';
		ans = char(s % 2 + '0') + ans;
		s /= 2;
		i--; j--;
	}
	return ans;
}
string addBinary(string A, string B) {
	string ans = "";
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	int a = A.length(); int b = B.length();
	int n = (a < b) ? a : b;
	int c = 0;
	int res = 0;
	int i = 0;
	for (; i < n; i++) {
		res = A[i] - '0' + B[i] - '0' + c;
		c = res / 2;
		res = res % 2;
		ans += to_string(res);
	}
	if (a > b) {
		while (i < A.length()) {
			res = A[i] - '0' + c;
			c = res / 2;
			res = res % 2;
			ans += to_string(res);
			i++;
		}
	}
	else if (b > a) {
		while (i < B.length()) {
			res = B[i] - '0' + c;
			c = res / 2;
			res = res % 2;
			ans += to_string(res);
			i++;
		}
	}
	if (c == 1)ans += "1";
	reverse(ans.begin(), ans.end());
	return ans;
}


int main()
{
	cout << addBinary("10100", "110");
}