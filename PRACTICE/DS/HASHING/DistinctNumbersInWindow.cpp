#include<bits/stdc++.h>
using namespace std;
vector<int> dNums(vector<int> &A, int B) {

	//answer array
	vector<int> ans;

	//initiaize n as size of an array A
	int n = A.size();

	//initialize map to store count of different elements in A
	map<int, int> m;

	//traverse on first B elements in A and store it in the map
	//0 to B-1 (0 based indexed)
	for (int i = 0; i < B; i++)
		m[A[i]]++;

	//put the count of first subarray of different elements in ans array
	ans.push_back(m.size());

	//initialize j which always point to the first element of the previous
	//subarray of size B (0 for 0 based indexed)
	int j = 0;

	//traverse on rest of the array
	for (int i = B; i < n; i++)
	{
		//decrease the count of first element of previous subarray
		m[A[j]]--;

		//if count becomes 0 then remove it from the map
		if (m[A[j]] == 0)
			m.erase(A[j]);

		//increase the count of present element in map
		m[A[i]]++;

		//increment the j pointer
		j++;

		//push the count of different element in ans array
		ans.push_back(m.size());
	}

	//return the answer array
	return ans;
}
int main()
{

}