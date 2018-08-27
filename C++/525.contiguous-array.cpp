class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // version 1 : force brute
        // TLE
        /*
        int res = 0, c0, c1, n = nums.size();
        for (int i = 0; i < n; i++) {
            c0 = nums[i] == 0 ? 1 : 0;
            c1 = nums[i];
            for (int j = i + 1; j < n; j++) {
                c0 += nums[j] == 0 ? 1 : 0;
                c1 += nums[j];
                res = c0 == c1 ? max(res, j - i + 1) : res;
            }
        }
        return res;
        */
        // version 2 : just like No.560, the target is 0, replace 0 by -1, find the langest of the subsequence sumed equles to target.
        
        
        int res = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (m.count(sum)) {
                res = max(res, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return res;
        
        
        /*
        int res = 0, sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1) ? 1 : -1;
            res = m.count(sum) ? max(res, i - m[sum]) : res;
            // when you use m[sum] then it = 0, so m.count(sum) != 0!!!!!!!!!!!!!so this version is wrong!!!!!
            m[sum] = (m.count(sum) > 0) ? m[sum] : i;   // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        
            
        }
        return res;
        */
    }
};