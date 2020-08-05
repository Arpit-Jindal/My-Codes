//Find a subarray of min length whose sum = k
#include<bits/stdc++.h>
using namespace std;
int buyingPlots(vector<int> &v, int k) {
	int n = v.size();
	int curr_length = 0;
	int ans = 2e9;
	int sum = 0;
	int i = 0;
	// int imin = 0; int jmin = 0;
	for (int j = 0; j < n; j++) {
		sum += v[j];

		while (sum > k)
			sum -= v[i++];

		if (sum == k) {
			curr_length = j - i + 1;
			if (ans > curr_length) {
				ans = curr_length;
				// imin = i;
				// jmin = j;
			}
		}
	}
	// while (imin <= jmin) {
	// 	cout << v[imin++] << " ";
	// }
	// cout << endl;
	return ans;
}
int main() {
	std::vector<int> v{3, 1, 2, 6, 7, 5};
	cout << buyingPlots(v, 12);
}