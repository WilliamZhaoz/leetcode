class Solution {
public:
    // version 1 : 2 pointer
    /*
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            while (numbers[left] + numbers[right] > target) {
                right--;
            }
            while (numbers[left] + numbers[right] < target) {
                left++;
            }
            if (numbers[left] + numbers[right] == target) {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            }
        }
        return res;  
    }
    */
    // version 2 : hash table
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i++) {
            if (hash.find(target - numbers[i]) != hash.end()) {
                res.push_back(hash.find(target - numbers[i]) -> second + 1);
                res.push_back(i + 1);
                return res;
            } 
            hash[numbers[i]] = i;
        }
        return res;
    }
    
    // version 3 : binary search  O(nlogn) time
    // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/51268/A-less-efficient-way-(binary-search)
    // version 4 : binary search O(logn) time
    // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/51251/A-O(logN)-binary-search-Java-Solution-0ms-beat-98
};