class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (1 << n); i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) tmp.push_back(nums[j]); 
            }
            res.push_back(tmp);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    
    // version 2 
    /*
    void helper(vector<vector<int>> & res, vector<int> &subset, vector<int> &nums, int start) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && i != start && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            helper(res, subset, nums, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        
        helper(res, subset, nums, 0);
        return res;
    }
    */
};