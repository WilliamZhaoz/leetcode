class Solution {
public:
    // version 1 : heap
    /*
    int findKthLargest(vector<int>& nums, int k) {   
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto n : nums) {
            q.push(n);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
          
    }
    */
    // version 2 : partition + divide and conquer
    /*
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (1) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) {
                return nums[pos];
            } else if (pos > k - 1) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
    }
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] <= pivot) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] >= pivot) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
    */
    // version 3 : select sort;
};