class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int dp1 = 1, dp2 = s[0] != '0';
        for (int i = 1; i < s.size(); i++) {
            int t1 = s[i] - '0', t2 = (s[i - 1] - '0') * 10 + t1;
            int tmp = (t1 != 0 ? dp2 : 0) + (t2 <= 26 && t2 >= 10 ? dp1 : 0);
            dp1 = dp2;
            dp2 = tmp;
            // cout<<dp1<<dp2<<t1<<t2<<tmp<<endl;
        }
        return dp2;
    }
};