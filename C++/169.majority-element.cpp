class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // version 1: moore voting
        /*
        int curM = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                curM = nums[i];
                count = 0;
            } 
            count += nums[i] == curM ? 1 : -1;
        }
        return curM;
        */
        // version 2: bit manipulation
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int c1 = 0, c0 = 0;
            for (auto num : nums) {
                c1 += (num & (1 << i)) != 0 ? 1 : 0;
                c0 += (num & (1 << i)) == 0 ? 1 : 0;
            }
            res |= c1 > c0 ? (1 << i) : 0;
        }
        return res;
    }
};