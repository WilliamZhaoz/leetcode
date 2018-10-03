class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // version 1 : hash table
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        int res = 0;
        for (auto mm : m) {
            if (k == 0 && mm.second > 1) {
                res++;
            }
            if (k > 0 && m.count(mm.first + k)) {
                res++;
            }
            
        }
        return res;
        // version 2 : sort and binary search 
        // version 3 : sort and 2 points
    }
};