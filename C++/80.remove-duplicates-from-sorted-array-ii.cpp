class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if ((slow > 1 && nums[fast] != nums[slow - 2]) || (slow <= 1)) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
};