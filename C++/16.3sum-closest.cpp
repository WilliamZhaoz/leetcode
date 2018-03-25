class Solution {
public:
    // version 1 : 1 while loop
    /*
    int threeSumClosest(vector<int>& nums, int target) {
        // diff = target - 3sum
        int diff = INT_MAX; // or do not use diff, use 3sum
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1, d = target - nums[l] - nums[r] - nums[i];
            while (l < r) {
                d = target - nums[l] - nums[r] - nums[i];
                if (d > 0) {
                    diff = abs(diff) < abs(d) ? diff : d;
                    l++;
                }
                if (d < 0) {
                    diff = abs(diff) < abs(d) ? diff : d;
                    r--;
                }
                if (d == 0) {
                    return target;
                }
            }  
        }
        // cout<<diff<<endl;
        return target - diff;
        
    }
    */
    // version 2 : more efficient 2 while in 1 while loop
    // https://leetcode.com/problems/3sum-closest/discuss/7906/7ms-and-o(n2)-java-solution
};