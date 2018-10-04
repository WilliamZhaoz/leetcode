// version 1: brute force
// version 2: all digits -> sort -> minute low bit -> minute heigh bit -> hour low bit -> hour heigh bit

class Solution {
public:
    // version 1 : compare one by one
    string nextClosestTime(string time) {
        set<int> s;
        
        for (int i = 0; i < time.size(); i++) {
            if (time[i] != ':') {
                s.insert(time[i] - '0');
            }
        }
        vector<int> nums;
        for (auto n : s) {
            nums.push_back(n);
        }
        int n = nums.size();
        string res = time;
        int min2 = time[4] - '0', min1 = time[3] - '0', hour2 = time[1] - '0', hour1 = time[0] - '0';
        if (min2 == nums[n - 1]) {
            res[4] = nums[0] + '0';
        } else {
            for (int i = 0; i < n; i++) {
                if (min2 == nums[i]) {
                    res[4] = nums[i + 1] + '0';
                    return res;
                }
            }
        }
        if (min1 == nums[n - 1] || min1 == 5) {
            res[3] = nums[0] + '0';
        } else {
            for (int i = 0; i < n; i++) {
                if (min1 == nums[i]) {
                    if (nums[i + 1] <= 5) {
                        res[3] = nums[i + 1] + '0';
                        return res;    
                    } else {
                        res[3] = nums[0] + '0';
                    }
                    
                }
            }
        }
        
        if (hour2 == nums[n - 1]) {
            res[1] = nums[0] + '0';
        } else {
            for (int i = 0; i < n; i++) {
                if (hour2 == nums[i]) {
                    if ((nums[i + 1] <= 4 && hour1 == 2) || hour1 < 2) {
                        res[1] = nums[i + 1] + '0';
                        return res;    
                    } else {
                        res[1] = nums[0] + '0';
                    }
                    
                }
            }
        }
        
        if (hour1 == nums[n - 1]) {
            return time;
        } else {
            for (int i = 0; i < n; i++) {
                if (hour1 == nums[i]) {
                    if (nums[i + 1] <= 2) {
                        res[0] = nums[i + 1] + '0';
                        return res;    
                    } else {
                        res[0] = nums[0] + '0';
                    }
                }   
            }
        }
        return res;  
        // version 2 : brute force, loop through all the time.
            
    }
};