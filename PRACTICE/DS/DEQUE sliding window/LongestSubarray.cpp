//Given n elements and a number K,find the longest subarray which has not more than K distinct elements.
//(It can have less than k)
#include<bits/stdc++.h>
using namespace std;
vector<int> subarray(vector<int> v, int k) {
	int n = v.size();
	vector<int> ans;
	unordered_map<int, int> freq;
	int start = 0, end = 0, de = 0, left = 0;

	for (int i = 0; i < n; i++) {
		freq[v[i]]++;
		if (freq[v[i]] == 1)
			de++;

		while (de > k) {
			freq[v[left++]]--;
			if (freq[v[left]] == 0)
				de--;
		}
		
		if (i - left + 1 > end - start + 1) {
			end = i;
			start = left;
		}
	}

	for (int i = start; i <= end; i++) {
		// cout << v[i] << " ";
		ans.push_back(i);
	}
	return ans;
}
int main() {
	std::vector<int> v{ 6, 5, 1, 2, 3, 2, 1, 4, 5 };
	subarray(v, 3);
}
