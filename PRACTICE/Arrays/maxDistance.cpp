#include<bits/stdc++.h>
using namespace std;
int maximumGap(const vector<int> &A) {
	vector<pair<int, int>> v;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(A[i], i));
	}
	sort(v.begin(), v.end());
	// vector<int> rightmax(n);
	// int maxval = INT_MIN;
	// for(int i=n-1;i>=0;i--){
	//     maxval = max(maxval,v[i].second);
	//     rightmax[i] = maxval;
	// }
	// int ans= INT_MIN;
	// for(int i=0;i<n;i++){
	//     maxval = rightmax[i] - v[i].second;
	//     if(maxval>ans)ans = maxval;
	// }
	int maxval = INT_MIN;
	int ans = INT_MIN;
	for (int i = n - 1; i >= 0; i--) {
		maxval = max(maxval, v[i].second);
		ans = max(ans, maxval - v[i].second);
	}
	return ans;

}

int main()
{

}