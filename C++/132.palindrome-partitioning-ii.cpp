/*
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int f[n + 1];
        bool isPalin[n][n];
        
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
            if (i + 1 < n) {
                isPalin[i][i + 1] = (s[i] == s[i + 1]);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                isPalin[i][j] = isPalin[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        f[0] = -1; // this option is to adjust to the case in which all the elements are same.
        for (int i = 1; i <= n; i++) {
            f[i] = i - 1;
            for (int j = 0; j < i; j++) {
                if (isPalin[j][i - 1]) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};
*/
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> dp1(s.size(), vector<bool>(s.size(), false));
        vector<int> dp2(s.size(), INT_MAX);
        dp2[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            dp1[i][i] = true;
            if (i > 0 && s[i] == s[i - 1]) {
                dp1[i - 1][i] = true;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 2; j <s.size(); j++) {
                dp1[i][j] = dp1[i + 1][j - 1] && s[i] == s[j];
            }
        }
        for (int i = 1; i < s.size(); i++) {
            dp2[i] = i;
            for (int j = 0; j <= i; j++) {
                if (dp1[j][i]) {
                    dp2[i] = min(dp2[i], j > 0 ? dp2[j - 1] + 1 : 0);
                }
            }
        }
        return dp2[s.size() - 1];
        
    }
};