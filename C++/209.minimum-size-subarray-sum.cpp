class Solution {
public:
    // version 1 : two points, slow and fast, with O(n) time complexity
    /*
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = nums.size(), res = l + 1, left = 0, right = 0, sum = 0;
        while (right < l) {
            while (sum < s && right < l) {
                sum += nums[right++]; 
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++]; 
            }
        }
        return res == l + 1 ? 0 : res;
    }
    */
    // version 2 : binary search, sum arry, with O(nlogn) time complexity
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int l = nums.size(), res = l + 1;
        vector<int> sums(l + 1, 0);
        for (int i = 0; i < l; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        for (int i = 0; i < l; i++) {
            auto it = lower_bound(sums.begin() + i, sums.end(), sums[i] + s);
            if (it == sums.end()) {
                break;
            }
            res = min(res, int(it - sums.begin() - i));
        }
        return  res == l + 1 ? 0 : res;
    }
};