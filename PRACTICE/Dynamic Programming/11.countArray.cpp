//https://www.hackerrank.com/challenges/construct-the-array/problem?h_r=internal-search
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long countArray(int n, int k, int x) {
	vector<long long> a(n), b(n);
	a[0] = x == 1 ? 1 : 0; //ends in x
	b[0] = x == 1 ? 0 : 1; //doesn't end in x
	for (int i = 1; i < n; i++) {
		a[i] = b[i - 1] % mod;
		b[i] = (a[i - 1] * (k - 1) + b[i - 1] * (k - 2)) % mod;
	}
	return a[n - 1];
}
int main() {
	int n, k, x; xin >> n >> k >> x;
	cout << countArray(n, k, x);
}