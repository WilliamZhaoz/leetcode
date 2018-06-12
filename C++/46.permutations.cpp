class Solution {
public:
    // recursive version
    /*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            res.push_back(vector<int>());
            return res;
        }
        helper(res, nums, nums.size() - 1);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &nums, int n) {
        if (n == 0) {
            res.push_back(nums);
        }
        for (int i = 0; i <= n; i++) {
            swap(nums[i], nums[n]);
            helper(res, nums, n - 1);
            swap(nums[i], nums[n]);
        }
    }
    */
    // non-recursive version
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            res.push_back(vector<int>());
            return res;
        }
        int n = nums.size();
        vector<int> s;
        vector<bool> inStack(n, false);
        s.push_back(-1);
        while (!s.empty()) {
            int top = s[s.size() - 1];
            s.pop_back();
            if (top != -1) {
                inStack[top] = false;
            }
            int next = -1;
            for (int i = top + 1; i < n; i++) {
                if (inStack[i] == false) {
                    next = i;
                    break;
                }
            }
            if (next == -1) {
                continue;
            }
            s.push_back(next);
            inStack[next] = true;
            for (int i = 0; i < n; i++) {
                if (!inStack[i]) {
                    s.push_back(i);
                    inStack[i] = true;
                }
            }
            
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                tmp.push_back(nums[s[i]]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};