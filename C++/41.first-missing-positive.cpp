class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			// put the element on its right position
			while (nums[i] >= 1 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				int temp = nums[i];
				nums[i] = nums[temp - 1];
				nums[temp - 1] = temp;
			}
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
};