class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = nums.size(), left = 0, right = 0;
        unordered_map<int, int> m;
        while (right < l) {
            if (right - left > k) {
                m[nums[left++]]--;        
            }
            m[nums[right]]++;
            if (m[nums[right]] > 1) {
                return true;
            }            
            right++;
        }
        return false;
    }
};