class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                /* 
                // these three lines code can not work in this case, left = right, swap the same number
                nums[left] ^= nums[right];
                nums[right] ^= nums[left];
                nums[left] ^= nums[right];
                */
                int tmp = nums[left];
                nums[left++] = nums[right];
                nums[right] = tmp;
            }
            right++;
        }
    }
    
};