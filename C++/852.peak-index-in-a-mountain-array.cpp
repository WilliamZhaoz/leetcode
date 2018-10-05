class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0, end = A.size() - 1;
        if (A[0] > A[1]) {
            return 0;
        }
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] > A[mid + 1]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (A[start] > A[start + 1]) {
            return start;
        }
        return end;
    }
};