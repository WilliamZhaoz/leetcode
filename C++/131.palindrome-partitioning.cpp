class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.size() == 0) {
            return res;
        }
        vector<string> sequence;
        helper(res, sequence, s, 0);
        return res;
    }
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void helper(vector<vector<string>> &res, vector<string> &sequence, string s, int depth) {
        if (depth == s.size()) {
            res.push_back(sequence);
            return;
        }
        for (int i = depth; i < s.size(); i++) {
            if (isPalindrome(s.substr(depth, i - depth + 1))) {
                sequence.push_back(s.substr(depth, i - depth + 1));
                helper(res, sequence, s, i + 1);
                sequence.pop_back();
            }
        }
    }
};