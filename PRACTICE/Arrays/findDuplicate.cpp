#include<bits/stdc++.h>
using namespace std;

//O(n) space
int repeatedNumber(const vector<int> &A) {
	vector<bool> count(A.size(), true);
	for (int i = 0; i < A.size(); i++) {
		if (count[A[i]] == true)
			count[A[i]] = false;
		else
			return A[i];
	}
}
//O(root(n)) space
int repeatedNumber(const vector<int> &A) {
	int n = A.size();
	int bs = sqrt(n - 1); //bucket size
	int count = ceil((double)(n - 1) / bs); //count of buckets
	int last = n - 1 - bs * (count - 1); // bucket size for last bucket
	vector<int> v(count, 0);
	for (int i = 0; i < n; i++) {
		v[(A[i] - 1) / bs]++;
	}
	int j;
	for (j = 0; j < count; j++) {
		if (j == count - 1) {
			if (v[j] > last)
				break;
		}
		if (v[j] > bs) {
			break;
		}
	}
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		if (A[i] > j * bs && A[i] <= (j + 1)*bs) {
			if (m[A[i]] == 1) return A[i];
			m[A[i]] = 1;
		}
	}
	return -1;
}

//O(root(n)) alternate method
int RepeatedNumber(vector<int> A) {
	int n = A.size();
	if (n == 0 || n == 1) {
		return -1;
	}

	int bs = (int)(sqrt(n - 1)); /* group size */
	int count = (int)ceil((double)(n - 1) / bs); /* group count */
	int last = n - 1 - bs * (count - 1); /* group size for last bucket */

	vector<int> v(count, 0);

	for (int i = 0; i < n; ++i) {
		int index = (A[i] - 1) / bs;
		int max = index == count - 1 ? last : bs;
		// if (index == count - 1)
		//    cout << max << ", " << index << ", " << (v[index] + 1) << ", " << A[i] << endl;
		v[index]++;
		if (v[index] > max) {
			vector<int> m(max, 0);
			for (int j = 0; j < n; ++j)
			{
				if ( ( (A[j] - 1) / bs ) == index )
				{
					int x = (A[j] - 1) % bs;
					m[x]++;
					if (m[x] > 1)
						return A[j];
				}
			}
		}
	}
	return -1;
}
//O(rootn) - rishabh
int repeatedNumber(const vector<int> &A) {
	int n = A.size() - 1;
	int bs = sqrt(n);
	int tb = (n / bs) + 1;
	vector<int> space(tb, 0);
	for (int i = 0; i <= n; ++i)
	{
		space[ (A[i] - 1) / bs ]++;
	}
	int ansBlock = tb - 1;
	for (int i = 0; i < tb; ++i)
	{
		if (space[i] > bs) ansBlock = i;
	}
	//cout<<"demn"<<ansBlock<<" "<<bs<<endl;
	unordered_map<int, int> hash;
	int ans = -1;
	for (int i = 0; i <= n; ++i)
	{
		if ((((ansBlock * bs) + 1) <= A[i]) && (((ansBlock + 1)*bs) >= A[i]))
		{
			hash[A[i]]++;
			//  cout<<A[i]<<" "<<hash[A[i]]<<endl;
			if (hash[A[i]] > 1) return A[i];
		}
	}
	return ans;
}
//O(1) space
int repeatedNumber(const vector<int> &A) {
	//floyd cycle approach
	//https://medium.com/solvingalgo/solving-algorithmic-problems-find-a-duplicate-in-an-array-3d9edad5ad41
	int n = A.size();
	if (!n) return -1;
	int slow = A[0], fast = A[A[0]]; //similar to do while loop
	while (slow != fast) {
		slow = A[slow];
		fast = A[A[fast]];
	}
	slow = 0;
	while (slow != fast) {
		slow = A[slow];
		fast = A[fast];
	}
	return slow;
}


int main()
{
	vector<int> v{1, 2, 3, 4, 5, 5};
	int ans = RepeatedNumber(v);
	cout << "\nans = " << ans << endl;
}