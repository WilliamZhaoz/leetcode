class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() <= 1 || matrix[0].size() <= 1) {
            return true;
        }
        for (int i = 0; i < matrix.size(); i++) {
            int m = i + 1, n = 0 + 1, tmp = matrix[i][0];
            while(m < matrix.size() && n < matrix[0].size()) {
                if (matrix[m][n] != tmp) {
                    return false;
                }
                tmp = matrix[m][n];
                m++; n++;
            }
        }
        for (int i = 1; i < matrix[0].size(); i++) {
            int m = 1, n = i + 1, tmp = matrix[0][i];
            while(m < matrix.size() && n < matrix[0].size()) {
                if (matrix[m][n] != tmp) {
                    return false;
                }
                tmp = matrix[m][n];
                m++; n++;
            }
        }
        return true;
    }
};