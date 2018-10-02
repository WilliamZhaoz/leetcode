class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid > num) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (left * left == num || right * right == num) {
            return true;
        }
        return false;
    }
};