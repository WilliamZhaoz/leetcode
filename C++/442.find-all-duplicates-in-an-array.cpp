class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // version 1: twice for loop
        /*
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i] - 1) {
                if (nums[nums[i] - 1] != nums[i]) {
                    swap(nums[nums[i] - 1], nums[i]);
                    i--;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 != i) {
                res.push_back(nums[i]);
            }
        }
        return res;
        */
        // version 2: once loop, use nums set tag.
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i] - 1 && nums[i] != -1) {
                if (nums[nums[i] - 1] != nums[i]) {
                    swap(nums[nums[i] - 1], nums[i]);
                    i--;
                } else {
                    res.push_back(nums[i]);
                    nums[i] = -1;
                }
            }
        }
        return res;
		// or like this
		/*
		vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
		*/
        
    }
};