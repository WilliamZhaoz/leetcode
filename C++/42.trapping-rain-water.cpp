class Solution {
public:
    // like 11, but now we need to sum all bars, for every bar, find the level height.
    /*
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            while (l < r && height[l] <= level) {
                res += level - height[l++];
            }
            while (l < r && height[r] <= level) {
                res += level - height[r--];
            }
            level = min(height[r], height[l]);
        }
        return res;
    }
    */
    // version 2, more clear but not easy to understand
    /*
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
    */
    // version 3, easy to understand but 3 pass
    // https://leetcode.com/problems/trapping-rain-water/discuss/17395/A-different-O(n)-approach-easy-to-understand-and-simple-code
    // version 4, stack version
    // https://leetcode.com/problems/trapping-rain-water/discuss/17414/A-stack-based-solution-for-reference-inspired-by-Histogram
    
};