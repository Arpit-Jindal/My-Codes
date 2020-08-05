#include<bits/stdc++.h>
using namespace std;
//O(n^3)
int maxSubrray1(vector<int> v) {
	int n = v.size();
	int maxsum = INT_MIN;
	int sum;
	//int l,r;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum = 0;
			for (int k = i; k <= j; k++) {
				sum += v[k];
			}
			if (sum > maxsum) {
				//l=i;r=j;
				maxsum = sum;
			}
		}
	}
	return maxsum;
}
//O(n^2)
int maxSubrray2(vector<int> v) {
	const int n = v.size();
	int maxsum = INT_MIN;
	int sum;
	int cumSum[n];

	cumSum[0] = v[0];
	for (int i = 1; i < n; i++) {
		cumSum[i] = v[i] + cumSum[i - 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			sum = cumSum[j] - cumSum[i - 1];
			if (sum > maxsum)
				maxsum = sum;
		}
	}
	return maxsum;
}
//O(n) - Kadane's Algo
int maxSubrray3(vector<int> v) {
	int max = INT_MIN;
	int count = 0;

	for (int i = 0; i < v.size(); i++) {
		// Increment the counter with the current value
		count = count + v[i];

		if (count > max) {
			max = count;
		}

		// If count is negative, we simply get rid of the past
		if (count < 0) {
			count = 0;
		}
	}
	return max;
}
int main()
{
	vector<int> v{ 2, -11, 2, 7, -8};
	cout << maxSubrray2(v);
}