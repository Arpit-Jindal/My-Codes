//What is the max sum of subarray of size k
#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int> &v,int k){
	int n = v.size();
	int max_sum = 0;
	int sum = 0;
	int i = 0;
	for(;i<k;i++){
		sum += v[i];
	}
	max_sum = sum;
	for(;i<n;i++){
		sum = sum + v[i] - v[i-k];
		if(max_sum<sum)
			max_sum = sum;
	}
	return max_sum;
}
int main()
{
	vector<int> v {1, 2, 3, 24, 5, 6, 7, 8};
	cout<<maxSum(v,3);
}