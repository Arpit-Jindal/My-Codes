#include<bits/stdc++.h>
using namespace std;
int main()
{
	if (nums.size() == 1) return nums[0];
	int s = 0, e = nums.size() - 1;
	int mid, ans;
	while (s < e) {
		mid = s + (e - s) / 2;
		if (e - s == 2) 
			return nums[s] ^ nums[e] ^ nums[e - 1];
		if ((e - mid) % 2 == 0) 
		{
			if (nums[mid] < nums[mid + 1])
				e = mid;
			else s = mid + 1;
		}
		else
		{
			if (nums[mid] == nums[mid + 1])
				e = mid - 1;
			else s = mid + 1;
		}
	}
	return nums[e];
}