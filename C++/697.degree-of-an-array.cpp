class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // version 1: O(n * k), n : nums.size(), k : the number of number frequently appear.
        /*
        unordered_map<int, int> m;
        int maxc = 0;
        // unordered_set<int> maxns;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            maxc = max(maxc, m[nums[i]]);
        }
        int res = INT_MAX;
        for (auto mm : m) {
            if (mm.second == maxc) {
                int start = INT_MAX, end = INT_MIN;
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] == mm.first) {
                        start = min(start, i);
                        end = max(end, i);
                    }
                }
                res = min(res, end - start + 1);
            }
        }
        return res;
        */
        // version 2 : O(n)
        unordered_map<int, int> counts, starts;
        int res = INT_MAX, maxc = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (starts.count(nums[i]) == 0) {
                starts[nums[i]] = i;
            }
            counts[nums[i]]++;
            if (counts[nums[i]] == maxc) {
                res = min(res, (int)i - starts[nums[i]]);
            }
            if (counts[nums[i]] > maxc) {
                res = (int)i - starts[nums[i]];
                maxc = counts[nums[i]];
            }
            
        }
        return res + 1;
        
    }
};