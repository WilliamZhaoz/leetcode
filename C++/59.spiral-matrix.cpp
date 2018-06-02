class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
        // use a only 2 dimension direction vector "order", 
        //    order = 1  : to right and down 
        //    order = -1 : to left and up
        vector<int> res;
        if (matrix.empty()) return res;
        int order = 1, dim1 = 0, dim2 = 0;
        float i = 0.5, j = 0;
        while (int(i) <= matrix.size() / 2 && int(j) <= matrix[0].size() / 2 && res.size() < matrix.size() * matrix[0].size()) {
            while (dim2 < matrix[0].size() - int(j) && dim2 > int(j) - 1) {
                res.push_back(matrix[dim1][dim2]);
                dim2 += order;
            }
            dim2 -= order;
            dim1 += order;
            while (dim1 < matrix.size() - int(i) && dim1 > int(i) - 1) {
                res.push_back(matrix[dim1][dim2]);
                dim1 += order;
            }
            dim1 -= order;
            dim2 -= order;
            i = i + 0.5;
            j = j + 0.5;
            order *= -1;
        }
        return res;
        */
        // use a 4 dimension direction vector "direct"
        vector<int> res;
        if (matrix.empty()) return res;
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        int direct = 0; // 0: go right 1 : go down 2: go left 3 :go up
        while(up <= down && left <= right) {
            if (direct == 0) {
                for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
                up += 1;
            }
            if (direct == 1) {
                for (int i = up; i <= down; i++) res.push_back(matrix[i][right]);
                right -= 1;
            }
            if (direct == 2) {
                for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
                down -= 1;
            }
            if (direct == 3) {
                for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
                left += 1;
            }
            direct = (direct + 1) % 4;
        }
        return res;
    }
    // use two 4 dimension direction vector 
    //    xd = [0, 1, 0, -1]
    //    yd = [1, 0, -1, 0]
    // every step only update (x, y) use xd,yd and update border index.
};