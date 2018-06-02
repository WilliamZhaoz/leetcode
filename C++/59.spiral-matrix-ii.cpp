class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0, right = n - 1, up = 0, down = n - 1, direct = 0, cur = 0;
        while (left <= right && up <= down) {
            if (direct == 0) {
                for (int i = left; i <= right; i++) res[up][i] = ++cur;
                up++;
            }
            if (direct == 1) {
                for (int i = up; i <= down; i++) res[i][right] = ++cur;
                right--;
            }
            if (direct == 2) {
                for (int i = right; i >= left; i--) res[down][i] = ++cur;
                down--;
            }
            if (direct == 3) {
                for (int i = down; i >= up; i--) res[i][left] = ++cur;
                left++;
            }
            direct = (direct + 1) % 4;
        }
        return res;
    }
};