int findPeak(vector<int> A) {
	for (int s = 0, e = A.size() - 1, mid = (s + e) / 2; s <= e; mid = (s + e) / 2) {
		if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid;
		if (A[mid - 1] < A[mid]) s = mid + 1;
		else e = mid - 1;
	}
	return -1;
}
int BS1(vector<int> A, int key, int peak) {
	for (int s = 0, e = peak, mid = (s + e) / 2; s <= e; mid = (s + e) / 2) {
		if (A[mid] == key) return mid;
		if (A[mid] < key)s = mid + 1;
		else e = mid - 1;
	}
	return -1;
}
int BS2(vector<int> A, int key, int peak) {
	for (int s = peak, e = A.size() - 1, mid = (s + e) / 2; s <= e; mid = (s + e) / 2) {
		if (A[mid] == key) return mid;
		if (A[mid] < key)e = mid - 1;
		else s = mid + 1;
	}
	return -1;
}
int Solution::solve(vector<int> &A, int B) {
	int peak = findPeak(A);
	int ans1 = BS1(A, B, peak);
	int ans2 = BS2(A, B, peak);
	if (ans1 == -1 && ans2 == -1)return -1;
	if (ans1 != -1)return ans1;
	return ans2;
}