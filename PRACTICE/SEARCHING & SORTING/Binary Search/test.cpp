#include<bits/stdc++.h>
using namespace std;
int findMedian(vector<vector<int> > &A) {
    int l = 2e9, h = -2e9;
    int r = A.size(), c = A[0].size();
    for (int i = 0; i < r; i++) {
        l = min(l, A[i][0]);
        h = max(h, A[i][c - 1]);
    }
    int desired = (r * c) / 2;
    while (l <= h) {
        int mid = (l + h) / 2, count = 0;
        for (auto v : A) {
            count += upper_bound(v.begin(), v.end(), mid) - v.begin();
        }
        count--;
        // cout << count << endl;
        if (count == desired) return mid;
        if (count < desired)l = mid + 1;
        else h = mid - 1;
    }
    return l;
}
int main() {
    vector<vector<int>> A{{1, 1, 3, 3, 3, 3, 3}};
    cout << findMedian(A);
}