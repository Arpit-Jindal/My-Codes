#include<bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
	int n = A.size();
	if (n < 2) return 0;
	int maxval = INT_MIN, minval = INT_MAX;
	for (int i = 0; i < n; i++) {
		maxval = max(maxval, A[i]);
		minval = min(minval, A[i]);
	}
	vector<int> maxbucket(n - 1, INT_MIN);
	vector<int> minbucket(n - 1, INT_MAX);
	float delta = (float)(maxval - minval) / (n - 1);

	for (int i = 0; i < n; i++) {
		if (A[i] == minval || A[i] == maxval) continue;
		int index = floor(A[i] - minval) / delta;
		maxbucket[index] = max(maxbucket[index], A[i]);
		minbucket[index] = min(minbucket[index], A[i]);
	}
	int prev_value = minval;
	int max_gap = 0;
	for (int i = 0; i < n - 1; i++) {
		if (minbucket[i] == INT_MAX)
			continue;
		max_gap = max(max_gap, minbucket[i] - prev_value);
		prev_value = maxbucket[i];
	}
	max_gap = max(max_gap, maxval - prev_value);
	return max_gap;
}

int main()
{

}