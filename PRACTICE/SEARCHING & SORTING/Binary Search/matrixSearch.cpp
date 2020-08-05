int Solution::searchMatrix(vector<vector<int> > &v, int a) {
    int n = v.size();
    int m = v[0].size();
    int l = 0, r = m * n - 1;
    while (l != r) {
        int mid = (l + r) / 2;
        if (v[mid / m][mid % m] == a) return 1;
        if (v[mid / m][mid % m] < a)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}
