int cntBits(vector<int> &A) {

	int ans = 0, count;
	for (int i = 0; i < 31; i++) {
		count = 0;
		for (int j = 0; j < A.size(); j++)
			if (A[j] & (1 << i))
				count++;

		ans = ans + (2 * count * (A.size() - count));
	}
	return (int)ans;
}