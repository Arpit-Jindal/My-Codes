double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    //size of A should always be smaller than B
    if (A.size() > B.size())
        return findMedianSortedArrays(B, A);

    int x = A.size();
    int y = B.size();
    if (x == 0) {
        return (y % 2 == 1) ? (double)B[y / 2] : (double)(B[y / 2 - 1] + B[y / 2]) / 2;
    }

    int low = 0;
    int high = A.size();
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
        //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
        int maxLeftX = (partitionX == 0) ? INT_MIN : A[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : A[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : B[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : B[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            //We have partitioned array at correct place
            // Now get max of left elements and min of right elements to get the median in case of even length combined array size
            // or get max of left for odd length combined array size.
            if ((x + y) % 2 == 0) {
                return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            } else {
                return (double)max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
            high = partitionX - 1;
        } else { //we are too far on left side for partitionX. Go on right side.
            low = partitionX + 1;
        }

    }

}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if (A.size() > B.size())
        return findMedianSortedArrays(B, A);
    int x = A.size();
    int y = B.size();
    if (!x) {
        int mid = y / 2;
        if (y & 1) return (double)B[mid];
        return (double)(B[mid - 1] + B[mid]) / 2;
    }
    int s = 0;
    int e = x - 1;
    while (s <= (e + 1)) {
        int px = floor((double)(s + e) / 2);
        int py = ((x + y + 1) / 2) - (px + 1) - 1 ;

        int maxLeftX = (px == -1) ? INT_MIN : A[px];
        int minRightX = (px == (x - 1)) ? INT_MAX : A[px + 1];
        int maxLeftY = (py == -1) ? INT_MIN : B[py];
        int minRightY = (py == (y - 1)) ? INT_MAX : B[py + 1];

        if (maxLeftY <= minRightX && maxLeftX <= minRightY) {
            if ((x + y) % 2 == 1)
                return (double)max(maxLeftX, maxLeftY);
            return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
        }
        if (maxLeftX > minRightY) {
            e = px - 1;
        } else {
            s = px + 1;
        }
    }
}