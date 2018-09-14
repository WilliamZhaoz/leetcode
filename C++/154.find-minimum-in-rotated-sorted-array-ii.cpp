class Solution {
public:
    // version 1 : only one for loop, in the worst case, the time complexity is O(n), e.g. 11111110111111
    /*
    int findMin(vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            res = min(res, nums[i]);
        }
        return res;
    }
    */
    // version 2: binary search, but in the worst cast, the time complexity is still O(n)
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            } else if(nums[mid] == nums[end]) {
                end--;
            } else {
                start = mid;
            }
        }
        return min(nums[start], nums[end]);
    }
};
