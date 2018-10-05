class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int la = A.size(), lb = B.size(), res = 0;
        vector<vector<int>> dp(la, vector<int>(lb, 0));
        for (int i = 0; i < la; i++) {
            if (A[i] == B[0]) {
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i < lb; i++) {
            if (B[i] == A[0]) {
                dp[0][i] = 1;
            }
        }
        for (int i = 1; i < la; i++) {
            for (int j = 1; j < lb; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};