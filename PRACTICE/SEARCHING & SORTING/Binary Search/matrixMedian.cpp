int BinarySearch(vector<vector<int> > &A, int l, int r, int n, int c) {
    if (l >= r)
        return l;
    int m = (l + r) / 2;
    int y = 0;
    for (auto v : A)
        y += upper_bound(v.begin(), v.end(), m) - v.begin();
    if (y >= (n * c + 1) / 2)
        return BinarySearch(A, l, m, n, c);
    else
        return BinarySearch(A, m + 1, r, n, c);
}
int Solution::findMedian(vector<vector<int> > &A) {
    // int i = INT_MIN, j = INT_MAX, n = A.size(), m = A[0].size();
    // return BinarySearch(A, i, j, n, m);

    int l = 2e9, h = -2e9;
    int r = A.size(), c = A[0].size();
    for (int i = 0; i < r; i++) {
        l = min(l, A[i][0]);
        h = max(h, A[i][c - 1]);
    }
    int desired = (r * c + 1) / 2;
    int ans;
    while (l <= h) {
        int mid = (l + h) / 2, count = 0;
        for (auto v : A) {
            count += upper_bound(v.begin(), v.end(), mid) - v.begin();
        }
        if (count < desired)l = mid + 1;
        else {
            ans = mid;
            h = mid - 1;
        }
    }
    return ans;
}