#define n 3
void Solution::sortColors(vector<int> &v) {
	int a[n] = {0};
	for (int i = 0; i < v.size(); i++)
		a[v[i]]++;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (a[i]--) {
			v[j++] = i;
		}
	}
}
