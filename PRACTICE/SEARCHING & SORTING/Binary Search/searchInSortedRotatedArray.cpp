#include<bits/stdc++.h>
using namespace std;
int searchIn(vector<int>A, int s, int e, int key) {
	if (s > e) return -1;
	int mid = (s + e) / 2;
	if (A[mid] == key) return mid;

	//left sorted?
	if (A[s] <= A[mid]) {
		//key in left?
		if (A[s] <= key && key <= A[mid])
			return searchIn(A, s, mid - 1, key);
		//in right!
		return searchIn(A, mid + 1, e, key);
	}

	//right sorted!
	else {
		//key in right?
		if (A[mid] <= key && key <= A[e])
			return searchIn(A, mid + 1, e, key);
		//in left!
		return searchIn(A, s, mid - 1, key);
	}

}
int main()
{
	vector<int> A{4, 5, 1, 2, 3};
	int key = 3;
	cout << searchIn(A, 0, A.size() - 1, key);
}