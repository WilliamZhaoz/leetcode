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
};