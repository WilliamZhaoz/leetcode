class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        int left, right, sum;
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                sum = target - nums[i] - nums[j];
                left = j + 1;
                right = len - 1;
                while (left < right) {
                    if (sum == nums[left] + nums[right]) {
                        tmp.clear();
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        res.push_back(tmp);
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                        
                    } else if (sum > nums[left] + nums[right]) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};