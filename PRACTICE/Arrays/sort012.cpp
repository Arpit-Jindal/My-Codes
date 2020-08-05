#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	vector<int> v{0, 2, 1, 2, 0, 1, 2, 1, 2, 1, 0, 0, 0, 0, 1, 2};
	int low = 0, mid = 0, high = v.size() - 1;
	while (mid <= high) {
		if (v[mid] == 1)
			mid++;
		else if (v[mid] == 0) {
			swap(v[low], v[mid]);
			low++; mid++;
		}
		else {
			swap(v[mid], v[high]);
			high--;
		}
	}

	printvector(v);
}