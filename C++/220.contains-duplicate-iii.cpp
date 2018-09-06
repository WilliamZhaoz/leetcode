class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int l = nums.size(), left = 0, right = 0;
        map<long long, int> m;
        while (right < l) {
            if (right - left > k) {
                m.erase(nums[left++]);        
            } 
            auto it_start = m.lower_bound((long long)nums[right] - (long long)t);
            if (it_start != m.end() && abs((long long)nums[right] - (long long)(*it_start).first) <= t) {
                return true;
            } 
            m[nums[right]]++;
            right++;
        }
        return false;
    }
};