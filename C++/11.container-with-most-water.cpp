class Solution {
public:
    int maxArea(vector<int>& height) {
        // tow pointer, one point to the start, another point to the end, the shorter need to move ahead until reach a taller line in there it is possible that the contiainers contains more water. 
        int res = 0;
        int left = 0, right = height.size() - 1;
        while (right > left) {
            int h = min(height[left], height[right]);
            res = max(res, h * (right - left));
			while (height[left] <= h) left++;
			while (height[right] <= h) right--;
			/*
			// no need to limit right > left because left++ will reach the right where height(left) = h then stop
            while (right > left && height[left] <= h) { // left is shorter
                left++;
            }
            while (right > left && height[right] <= h) { // right is shorter
                right--;
            }
			*/
        }
        return res;

    }
};