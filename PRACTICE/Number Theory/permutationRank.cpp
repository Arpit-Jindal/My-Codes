#include<bits/stdc++.h>
using namespace std;
#define mod 1000003
long int fact(int n) {
	return (n == 1 || n == 0) ? 1 : (n * fact(n - 1)) % mod;
}
long int modInverse(int a, int m)
{
	a = a % m;
	for (long int x = 1; x < m; x++)
		if ((a * x) % m == 1)
			return x;
	return 0;
}
//without repeats - approach 1  = O(n^2)
int findRank1(string A) {
	int n = A.length();
	long int ans = 1;
	for (int i = 0; i < n; i++) {

		int count = 0;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[i])
				count++;
		}

		ans += (count % mod * fact(n - i - 1) % mod ) % mod;
	}
	return ans % mod;
}
//without repeats - approach 2 = O(n^2)
int findRank2(string A) {
	string B = A;
	sort(B.begin(), B.end());
	long int ans = 0;
	int j = 0;
	long int n = A.length() - 1;
	vector<pair<char, int>> v;
	for (int i = 0; i < B.length(); i++) {
		v.push_back(make_pair(B[i], 0));
	}
	while (j < A.length()) {
		int i = 0;
		while (v[i].first != A[j]) {
			if (v[i].second == 0)
				ans = (ans + fact(n)) % mod;
			i++;
		}
		v[i].second = 1;
		j++;
		n--;
	}
	return (ans + 1);
}
//without repeats - approach 3  = O(n)
int findRank3(string A) {
	int l = A.length();
	int count[CHAR_MAX] = {0};
	int mul;
	int ans = 1;
	//populate and increase count
	for (int i = 0; i < l; i++)
		count[A[i]]++;
	for (int i = 1; i < CHAR_MAX; i++)
		count[i] += count[i - 1];
	for (int i = 0; i < l; i++) {
		mul = fact(l - 1 - i) % mod;
		ans += ((count[A[i]] - 1) * mul) % mod;
		//update count
		for (int j = A[i]; j < CHAR_MAX; j++)
			count[j]--;
	}
	return ans % mod;
}

//with duplicates
int FindRank(string A) {
	int n = A.length();
	long int ans = 1;
	for (int i = 0; i < n; i++) {

		int count = 0;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[i])
				count++;
		}
		vector<int> v(52, 0);
		for (int j = i; j < n; j++) {
			if (A[j] >= 'A' && A[j] <= 'Z')
				v[A[j] - 'A']++;
			else
				v[A[j] - 'a' + 26]++;
		}
		int fac = 1;
		for (int i = 0; i < v.size(); i++)
			fac = (fac % mod * fact(v[i]) % mod ) % mod;

		ans += (count % mod * fact(n - i - 1) % mod * modInverse(fac, mod) % mod ) % mod;
	}
	return ans % mod;
}

int main()
{
	cout << findRank1("DTNGJPURFHYEW") << endl;
	cout << findRank2("DTNGJPURFHYEW") << endl;
	cout << findRank3("DTNGJPURFHYEW") << endl;
}