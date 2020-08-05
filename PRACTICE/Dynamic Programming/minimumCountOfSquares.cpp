#include<bits/stdc++.h>
using namespace std;
int minCount_dp(int n) {
	int *arr = new int[n + 1];
	arr[0] = 0; arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = i;
		for (int j = 1; j <= sqrt(i); j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	return arr[n];
}
int minCount_memoization_helper(int n, int* arr) {
	//Base Case
	if (n <= 3) return n;

	//Check if ans is already present
	if (arr[n] != -1) return arr[n];

	int ans = INT_MAX;
	for (int i = 1; i <= sqrt(n); i++) {
		int ans1 = minCount_memoization_helper(n - i * i, arr) + 1;
		ans = min(ans, ans1);
	}
	arr[n] = ans;
	return arr[n];
}
int minCount_memoization(int n) {
	int *arr = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = -1;
	}
	return minCount_memoization_helper(n, arr);
}
int minCount_recursive(int n) {
	//Base Case
	if (n <= 3) return n;

	int ans = INT_MAX;
	for (int i = 1; i <= sqrt(n); i++) {
		int ans1 = minCount_recursive(n - i * i) + 1;
		ans = min(ans, ans1);
	}
	return ans;
}
int main()
{
	cout << minCount_memoization(82) << endl;
	cout << minCount_dp(82) << endl;
	cout << minCount_recursive(7) << endl;
}