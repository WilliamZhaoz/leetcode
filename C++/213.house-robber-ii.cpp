class Solution {
public:
    int rob(vector<int>& nums) {
        // can not rob both the first and the last room, so return max(do not rob the first room, do not rob the last room)
        if (nums.size() <= 1) {
            return nums.empty() ? 0 : nums[0];
        }
        int prof1 = 0, prof2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            int tmp = prof2;
            prof2 = max(prof2, prof1 + nums[i]);
            prof1 = tmp;
        }
        int prof3 = 0, prof4 = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int tmp = prof4;
            prof4 = max(prof4, prof3 + nums[i]);
            prof3 = tmp;
        }
        return max(prof2, prof4);
        
    }
};