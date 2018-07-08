class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_t;
        for (int i = 0; i < nums.size(); i++) {
            if (hash_t.find(nums[i]) != hash_t.end()) {
                return true;
            }
            hash_t[nums[i]]++;
        }
        return false;
    }
};