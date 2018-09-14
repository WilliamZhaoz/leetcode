class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        k %= l;
        if (l == 0 || k == 0) {
            return;
        }
        reverse(nums, 0, l - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, l - 1);
        
    }
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            nums[start] ^= nums[end];
            nums[end] ^= nums[start];
            nums[start] ^= nums[end];
            start++;
            end--;
        }
    }
};