class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = m * n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2, mm = mid / n, nn = mid % n, midval = matrix[mm][nn];
            
            if (target == midval) {
                return true;
            } else if (target > midval) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int mm = left / n, nn = left % n;
        if (target == matrix[mm][nn]) {
            return true;
        }
        mm = right / n, nn = right % n;
        if (target == matrix[mm][nn]) {
            return true;
        }
        return false;
        
    }
};