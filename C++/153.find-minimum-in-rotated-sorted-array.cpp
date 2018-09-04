class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) {
			return INT_MAX;
		}
		int start = 0, end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < nums[0]) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		// cout<<start<<end;
		if (nums[start] < nums[0]) {
			return nums[start];
		}
		if (nums[end] < nums[0]) {
			return nums[end];
		}
		return nums[0];
	}
};