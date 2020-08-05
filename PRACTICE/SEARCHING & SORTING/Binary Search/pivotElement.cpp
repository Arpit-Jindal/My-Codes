//search in rotated array using a pivot element
#include<bits/stdc++.h>
using namespace std;
int pivot(vector<int> &v) {
	int s = 0, e = v.size() - 1, mid;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (mid > s && v[mid] < v[mid - 1])
			return mid - 1;
		if (mid < e && v[mid] > v[mid + 1])
			return mid;
		if (v[s] < v[mid]) //left sorted
			s = mid + 1; //find pivot in right part
		else
			e = mid - 1;
	}
	return e;
}
int recursiveBS(vector<int> &v, int f, int l, int x)
{
	if (f > l)
		return -1;
	int mid = (f + l) / 2;
	if (v[mid] == x)
		return mid;
	else if (v[mid] > x)
		return recursiveBS(v, f, mid - 1, x);
	else
		return recursiveBS(v, mid + 1, l, x);
}
int main()
{
	vector<int> v{9, 9, 9, 9, 9, 9, 9, 4, 5, 6, 7};
	int p = pivot(v);
	int key = 7;//key to be searched
	if (key >= v[0])
		cout << recursiveBS(v, 0, p, key);
	else
		cout << recursiveBS(v, p + 1, v.size() - 1, key);

}