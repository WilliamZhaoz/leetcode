class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) {
            return 0;
        }
        long long start = 1, end = n;
        while (start + 1 < end) {
            long long mid = start + (end - start) / 2;
            if ((1 + (double)mid) / 2 * (double)mid >= n) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if ((1 + (double)end) / 2 * (double)end <= n) {
            return end;
        }
        return start;
    }
};