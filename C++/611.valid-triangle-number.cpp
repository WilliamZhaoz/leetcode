class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // version 1 : sort + brute force + pruning O(n^3)
        /*
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum2 = nums[i] + nums[j];
                for (int k = j + 1; k < n; k++) {
                    if (sum2 <= nums[k]) {
                        break;
                    } else {
                        res++;
                    }
                }
            }
        }
        
        return res;
        */
        // version 2 : sort + 2 points O(n^2)
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += right - left;
                    right--;
                } else {
                    ++left;
                }
            }
    
        }
        return res;
    }
};