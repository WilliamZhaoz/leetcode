// version 1
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

// version 2 :
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int start = 0, end = nums.size();
        sort(nums.begin(), nums.end());
        for (; start < end; start++) {
            int tar = target - nums[start];
            vector<vector<int>> r = threeSum(nums, tar, start + 1, end);
            for (int j = 0; j < r.size(); j++) {
                r[j].insert(r[j].begin(), nums[start]);
                res.push_back(r[j]);
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums, int target, int start, int end) {
        vector<vector<int>> res;
        for (; start < end; start++) {
            int tar = target - nums[start];
            vector<vector<int>> r = twoSum(nums, tar, start + 1, end);
            for (int j = 0; j < r.size(); j++) {
                r[j].insert(r[j].begin(), nums[start]);
                res.push_back(r[j]);
            }
        }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start, int end) {
        vector<vector<int>> res;
        end -= 1;
        while (start < end) {
            int cur = nums[start] + nums[end];
            if (cur == target) {
                vector<int> tmp;
                tmp.push_back(nums[start]);
                tmp.push_back(nums[end]);
                res.push_back(tmp);
                start++;
                end--;
            } else if (cur > target) {
                end--;    
            } else {
                start++;
            }
            
        }
        return res;
    }
};