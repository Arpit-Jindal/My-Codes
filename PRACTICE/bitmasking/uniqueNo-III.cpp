//all no. occuring thrice except one no. find that no.
#include<iostream>
using namespace std;
int singleNumber(const vector<int> &v) {
	int res = 0;
	for (int i = 0; i < 32; i++) {
		int ans = 0;
		for (auto x : v) ans += (x & (1 << i)) ? 1 : 0;
		if (ans % 3)res += (1 << i);
	}
	return res;
}

int singleNumber(const vector<int>& A) {
	int result = 0;
	int x, sum;
	for (int i = 0; i < 32; i++) {
		sum = 0;
		x = (1 << i);
		for (int j = 0; j < A.size(); j++)
			if (A[j]&x)
				sum++;

		if (sum % 3)
			result |= x;
	}
	return result;
}
int main()
{
	int a[] = {1, 1, 1, 2, 3, 2, 3, 2, 4, 4, 12, 3, 4, 5, 5, 5, 6, 7, 6, 7, 7, 6};
	int len = sizeof(a) / sizeof(a[0]);
	int ans[32] = {0};
	for (int i = 0; i < len; i++) //extract bits of every no. and update the ans array
	{
		int pos = 0;
		while (a[i] > 0)
		{
			ans[pos] += (a[i] & 1);
			pos++;
			a[i] >>= 1;
		}
	}
	//Take mod of ans array with 3
	int result = 0;
	for (int i = 0; i < 32; i++ )
	{
		ans[i] %= 3;
		if (ans[i])
			result += (1 << i);
	}
	cout << result;
}