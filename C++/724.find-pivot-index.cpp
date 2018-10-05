class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // version 1 : 2 accumulate vector O(n) space complexity
        /*
        int l = nums.size(), suml = 0, sumr = 0;
        vector<int> left(l, 0), right(l, 0);
        for (int i = 1; i < l; i++) {
            suml += nums[i - 1];
            sumr += nums[l - i];
            left[i] = suml;
            right[l - i - 1] = sumr;
        }
        for (int i = 0; i < l; i++) {
            if (left[i] == right[i]) {
                return i;
            }
        }
        return -1;
        */
        // version 2: O(1) space 
        int sum = accumulate(nums.begin(), nums.end(), 0), cursum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cursum += nums[i];
            if (sum - nums[i] == 2 * (cursum - nums[i])) {
                return i;
            }
        }
        return -1;
        
    }
};