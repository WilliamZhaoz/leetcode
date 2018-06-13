class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            res.push_back(vector<int>());
        }
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> p;
        helper(res, nums, p, visited);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &nums, vector<int> &p, vector<bool> &visited) {
        if (p.size() == nums.size()) {
            res.push_back(p);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            visited[i] = true;
            p.push_back(nums[i]);
            helper(res, nums, p, visited);
            p.pop_back();
            visited[i] = false;
        }
    }
};