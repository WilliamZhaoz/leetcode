class Solution {
public:
    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            hashTable.insert({nums[i], i});
            auto f = hashTable.find(target - nums[i]);
            if (f != hashTable.end()) {
                if (f->second != i) {
                    res.push_back(i);
                    res.push_back(f->second);
                }
            }
        }
        return res;
    }
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            auto f = hashTable.find(target - nums[i]);
            if (f != hashTable.end()) {
                res.push_back(i);
                res.push_back(f->second);
            }
            // hashTable.insert({nums[i], i});
            hashTable[nums[i]] = i;
        }
        return res;
    }
};