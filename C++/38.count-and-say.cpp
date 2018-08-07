class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 0; i < n - 1; i++) {
            res = helper(res);
        }
        return res;
    }
    string helper(string s) {
        string res;
        int c = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i != s.size() - 1 && s[i] == s[i + 1]) {
                c++;
            } else {
                res = res + to_string(c) + s[i];
                c = 1;
            }
        }
        return res;
    }
};