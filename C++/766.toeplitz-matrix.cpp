class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int val = matrix[i][0], mm = i, nn = 0;
            while(mm >= 0 && nn >= 0 && mm < m && nn < n) {
                if (matrix[mm++][nn++] != val) {
                    return false;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int val = matrix[0][i], mm = 0, nn = i;
            while(mm >= 0 && nn >= 0 && mm < m && nn < n) {
                if (matrix[mm++][nn++] != val) {
                    return false;
                }
            } 
        }
        return true;
    }
};