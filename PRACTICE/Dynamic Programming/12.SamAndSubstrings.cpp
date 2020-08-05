//https://www.hackerrank.com/challenges/sam-and-substrings/problem?h_r=internal-search
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int substrings(string s) {
	long long ans = s[0] - '0';
	long long temp = s[0] - '0';
	int n = s.length();
	for (int i = 1; i < n; i++) {
		temp = (temp * 10 + (s[i] - '0') * (i + 1)) % mod;
		ans = (ans + temp) % mod;
	}
	return ans;
}
int main() {
	string t; cin >> t;
	cout << substrings(t);
}