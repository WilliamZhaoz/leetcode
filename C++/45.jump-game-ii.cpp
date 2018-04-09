class Solution {
public:
    int jump(vector<int>& nums) {
        // version 1 : greedy O(n)
        int res = 0, cur = 0, pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > pre) {
                res++;
                pre = cur;
            }
            cur = max(cur, i + nums[i]);
        }
        return res;
        // version 2 : dp O(n2)
    }
};