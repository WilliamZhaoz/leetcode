class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int res = 0, left = 0, product = 1, n = nums.size();
        for (int i = 0; i < n; i++) {
            product *= nums[i];
            /*
            // some big data case can not ac, do not know why
			// I found the problem, in this version, product need to be double type, because product /= nums[] will lose the accuracy in int. 
            if (product < k) {
                res += i - left + 1;
            } else {
                product /= nums[left++];
                product /= nums[i];
                i--;  
            }
            */
            while (product >= k) {
                product /= nums[left++];
            }
            res += i - left + 1;
        }
        return res;
    }
};