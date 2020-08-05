#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//dp
int bst_dp(int h) {
	int *arr = new int[h + 1];
	arr[0] = 1; arr[1] = 1;
	for (int i = 2; i <= h; i++) {
		int x = arr[i - 1];
		int y = arr[i - 2];
		int temp1 = (int) ( ( (long)(x) * x ) % mod);
		int temp2 = (int) ( (2 * (long)(x) * y) % mod);
		int ans = (temp1 + temp2) % mod;
		arr[i] = ans;
	}
	return arr[h];
}
//memoisation
int bst_memoisation_helper(int h, int *arr) {
	if (h <= 1) return 1;
	if (arr[h] != 0) return arr[h];

	int x = bst_memoisation_helper(h - 1, arr);
	int y = bst_memoisation_helper(h - 2, arr);

	int temp1 = (int) ( ( (long)(x) * x ) % mod);
	int temp2 = (int) ( (2 * (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;
	arr[h] = ans;
	return ans;
}
int bst_memoisation(int h) {
	if (h <= 1)return 1;
	int *arr = new int[h + 1];
	for (int i = 0; i <= h; i++) {
		arr[i] = 0;
	}
	return bst_memoisation_helper(h, arr);
}
//recursive
int noOfBalancedBST(int h) {
	if (h <= 1) return 1;

	int x = noOfBalancedBST(h - 1);
	int y = noOfBalancedBST(h - 2);

	int temp1 = (int) ( ( (long)(x) * x ) % mod);
	int temp2 = (int) ( (2 * (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;
	return ans;

}
int main()
{
	int n;
	cin >> n;
	cout << bst_dp(n) << endl;
	cout << bst_memoisation(n) << endl;
	cout << noOfBalancedBST(n) << endl;
}