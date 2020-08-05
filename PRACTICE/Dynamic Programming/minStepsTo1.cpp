#include<bits/stdc++.h>
using namespace std;

//DP
int minstepsto1_dp(int n) {
	if (n <= 1)return 0;
	int *arr = new int[n + 1];
	arr[0] = arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		int ans = 1 + arr[i - 1];
		if (i % 2 == 0) ans = min(ans, 1 + arr[i / 2]);
		if (i % 3 == 0) ans = min(ans, 1 + arr[i / 3]);
		arr[i] = ans;
	}
	return arr[n];
}

// Memoization
int minstepsto1_memoization_helper(int n, int *arr) {
	// Base Case
	if (n <= 1) return 0;

	// Check if output already exists
	if (arr[n] != -1) return arr[n];

	int x = minstepsto1_memoization_helper(n - 1, arr);
	int y = INT_MAX, z = INT_MAX;
	if (n % 2 == 0)
		y = minstepsto1_memoization_helper(n / 2, arr);
	if (n % 3 == 0)
		z = minstepsto1_memoization_helper(n / 3, arr);

	// Save output for future use
	arr[n] = min(x, min(y, z)) + 1;

	return arr[n];
}

int minstepsto1_memoization(int n) {
	if (n <= 1) return 0;
	int *arr = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = -1;
	}
	return minstepsto1_memoization_helper(n, arr);
}

//Recursive
int minstepsto1_recursive(int n) {
	if (n <= 1) return 0;
	int x = minstepsto1_recursive(n - 1);
	int y = INT_MAX, z = INT_MAX;
	if (n % 2 == 0)
		y = minstepsto1_recursive(n / 2);
	if (n % 3 == 0)
		z = minstepsto1_recursive(n / 3);

	return min(x, min(y, z)) + 1;
}
int main()
{
	cout << "Recursive : " << minstepsto1_recursive(11) << endl;
	cout << "Memoization : " << minstepsto1_memoization(11) << endl;
	cout << "DP : " << minstepsto1_dp(11) << endl;
}