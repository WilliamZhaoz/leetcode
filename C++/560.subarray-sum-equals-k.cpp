class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // version 1 : force brute
        /*
        int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = nums[i];
            if (sum == k) {
                res++;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                sum +=  nums[j];
                if (sum == k) {
                    res++;
                }
            }
        }
        return res;
        */
        // version 2: hash tabel, if (sum - k) is in sums, then sum - (sum - k) = k
        int res = 0, sum = 0;
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += m[sum - k];
            m[sum]++;
        }
        return res;
        
    }
};