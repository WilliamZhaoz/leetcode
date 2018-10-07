class Solution {
public:
    string longestPalindrome(string s) {
        // version 1 : brute force, O(n2)
        // version 2 : dp, O(n2)
        //             dp[i][j] = 1 if i == j
        //                      = s[i] == s[j] if j = i + 1
        //                      = s[i] == s[j] && dp[i + 1][j - 1] if j > i + 1
        // version 3: Manacher's algorithm
        //            1). insert # into the string, add $ at the begining
        //            2). p[i]: the radius of the palindrome with i as the centor
        //            3). mx, id : current max position mx with the centor id
        //            4). p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1
        //            5). return s.substr((resCenter - resLen) / 2, resLen - 1)
        string t = "$#";
        for (int i = 0; i < s.size(); i++)
        {
            t += s[i];
            t += "#";
        }    
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) {
                ++p[i];
            }
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
};