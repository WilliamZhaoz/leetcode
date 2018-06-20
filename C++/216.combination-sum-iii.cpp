class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k <= 0 || n <= 0 || n > 55) {
            return res;
        }
        vector<int> combination;
        helper(res, combination, 1, k, n);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &combination, int start, int k, int n) {
        if (combination.size() == k) {
            if (n == 0) {
                res.push_back(combination);    
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            combination.push_back(i);
            helper(res, combination, i + 1, k, n - i);
            combination.pop_back();
        }
    }
};