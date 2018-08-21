
class Solution {
public:
    // version 1 : backtracking
    /*
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        if (p.size() > 1 && p[1] == '*') {
            // (s, p.substr(2)) : * repeat 0 times
            // (s.substr(1), p) : * repeat 1 times, recursive call the isMatch -> repeat * times;
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        } else {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
    */
    // version 2 : dynamic programming
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false)); // dp[i][j] : isMatch(s[0, i), p[0, j))
        dp[0][0] = true;
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

