class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        int maxv = *it;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] * 2 > maxv && nums[i] != maxv) {
                return -1;
            }
        }
        return it - nums.begin();
    }
};