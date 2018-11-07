class Solution {
public:
    // version 1 : dp, O(n2) space complexity
    /*
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
    */
    // version 1 : dp, O(n) space complexity
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int res = 0, pre = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(m + 1, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i <= m; ++i) {
                int t = dp[i];
                if (matrix[i - 1][j] == '1') {
                    dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                    res = max(res, dp[i]);
                } else {
                    dp[i] = 0;
                }
                pre = t;
            }
        }
        return res * res;
        
    }
};
