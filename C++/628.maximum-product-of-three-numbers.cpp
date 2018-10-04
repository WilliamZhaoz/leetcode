class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN, mx2 = mx1, mx3 = mx1, mn1 = INT_MAX, mn2 = mn1;
        for (auto n : nums) {
            if (n >= mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = n;
            } else if (n >= mx2) {
                mx3 = mx2;
                mx2 = n;
            } else if (n >= mx3) {
                mx3 = n;
            }
            if (n <= mn1) {
                mn2 = mn1;
                mn1 = n;
            } else if (n <= mn2) {
                mn2 = n;
            }
    }
        return max(mn1 * mn2 * mx1, mx1 * mx2 * mx3);
        
    }
};