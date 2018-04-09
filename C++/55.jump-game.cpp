class Solution {
public:
		// version 1 : greedy O(n)
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }
        int max_pos = 0;
        for (int i = 0; i < nums.size() && max_pos >= i; i++) {
            max_pos = max(max_pos, i + nums[i]);
        }
        return max_pos >= nums.size() - 1;
    }
    // version 2 : dp O(n2)
};