// version 1 : 
/*
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 1;
        unordered_set<int> ss;
        ss.insert(nums[0]); // we can also use a visited list to record whether it was visited.

        for (int i = 0; i < nums.size(); i++) {
            if (ss.count(nums[i])) { 
                continue; // if the element is visited, it will return the old ciecle, so just skip it.
            }
            int tmp = 1;
            unordered_set<int> s; // we can only compare cur number is equal to the start number.  
            int cur = nums[i];
            s.insert(cur);
            while (1) {
                if (s.count(nums[cur])) {
                    res = max(res, tmp);
                    break;  
                }
                tmp++;
                ss.insert(nums[cur]);
                cur = nums[cur];
            } 
        }
        return res;
        
    }
};
*/
// version 2: like version 1 but more clear.
/*
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 1;
        vector<bool> visited(nums.size(), false);
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) { 
                continue; 
            }
            visited[i] = true;
            int start = i, c = 1, cur = nums[i];
            while (nums[cur] != nums[start]) {
                c++;
                visited[cur] = true;
                cur = nums[cur];
                res = max(res, c);
            } 
        }
        return res;
        
    }
};
*/
// version 3 : space complexity optimization

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) { 
                continue; 
            }
            int start = i, c = 1, cur = nums[start];
            nums[i] = -1;
            while (cur != start) {
                c++;
                int tmp = nums[cur];
                nums[cur] = -1;
                cur = tmp;
                res = max(res, c);
            } 
        }
        return res;
        
    }
};
