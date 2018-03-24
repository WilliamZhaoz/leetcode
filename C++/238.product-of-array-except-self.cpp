class Solution {
public:
    // my solution
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        vector<int> res;
        int tmp = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                tmp *= nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) {
                res.push_back(0);
            } else if (zeroCount == 1) {
                if (nums[i] == 0) {
                    res.push_back(tmp);
                } else {
                    res.push_back(0);
                }
            } else {
                res.push_back(tmp / nums[i]);
            }
        }
        return res;
    }
    */
    // version 2 : O(n) time twice loop
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 0, tmp = 1; i < nums.size(); i++) {
            res[i] *= tmp; // res[i] = tmp;
            tmp *= nums[i];
        }
        for (int i = nums.size() - 1, tmp = 1; i >= 0; i--) {
            res[i] *= tmp;
            tmp *= nums[i];
        }
        return res; 
    }
    */
    // version 3 :O(n) time once loop
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 0, l = 1, r = 1; i < nums.size(); i++) {
            res[i] *= l;
            l *= nums[i];
            res[nums.size() - 1 - i] *= r;
            r *= nums[nums.size() - 1 - i];
        }
        return res;
    }
    
};