class Solution {
public:
    int mySqrt(int x) {
        long long start = 0, end = x;
        while (start + 1 < end) {
            long long mid = start + (end - start) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return start ? start : end;
    }
};