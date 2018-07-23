class Solution {
public:
    int totalNQueens(int n) {
        vector<int> pos(n, INT_MIN);
        int res = 0;
        helper(pos, res, 0);
        return res;
    }
    void helper(vector<int> &pos, int &res, int row) {
        int n = pos.size();
        if (row == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(pos, row, i)) {
                pos[row] = i;
                helper(pos, res, row + 1);
                pos[row] = INT_MIN;
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i] == col || abs(i - row) == abs(pos[i] - col)) {
                return false;
            }
        }
        return true;
    }
};