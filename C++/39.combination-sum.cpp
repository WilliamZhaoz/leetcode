class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) {
            res.push_back(vector<int>());
            return res;
        }
        vector<int> subset;
        helper(res, candidates, subset, target, 0, 0);
        /*
        // use start to avoid duplicate case, the different is the new start = i but i + 1 in for circulation
        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        */
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &nums, vector<int> &subset, int target, int curSum, int start) {
        if (curSum == target) {
            res.push_back(subset);
        }
        if (curSum > target) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            curSum += nums[i];
            helper(res, nums, subset, target, curSum, i);
            subset.pop_back();
            curSum -= nums[i];
        }
    }
};

// new version 6/21/2018
/*
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0) {
            return res;
        }
        vector<int> c;
        helper(res, c, candidates, target, 0);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &c, vector<int> &candidates, int target, int start) {
        if (target <= 0) {
            if (target == 0) {
                res.push_back(c);
            }
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            c.push_back(candidates[i]);
            target -= candidates[i];
            helper(res, c, candidates, target, i);
            c.pop_back();
            target += candidates[i];
        }
    }
};
*/