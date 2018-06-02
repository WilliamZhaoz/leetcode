class Solution {
public:
    // binary version
    /*
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> tmp;
            // 1 << n is 2^n
            // each subset equals to an binary integer between 0 .. 2^n - 1
            // 0 -> 000 -> []
            // 1 -> 001 -> [1]
            // 2 -> 010 -> [2]
            // ..
            // 7 -> 111 -> [1,2,3]
            for (int j = 0; j < n; j++) {
                // check whether the jth digit in i's binary representation is 1
                if ((i & (1 << j)) != 0) {
                    tmp.push_back(nums[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;   
    }
    */
     // dfs
    /*
    void helper(vector<vector<int>> & res, vector<int> &subset, vector<int> &nums, int start) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            helper(res, subset, nums, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        helper(res, subset, nums, 0);
        return res;
    }
    */  
    // bfs
   
    
};