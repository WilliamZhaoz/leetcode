class Solution {
public:
    vector<string> k {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }
        string s;
        helper(res, digits, s);
        return res;
    }
    void helper(vector<string> &res, string digits, string s) {
        if (s.size() == digits.size()) {
            res.push_back(s);
        }
        // tips 1 : this line can also use c++ 11 
        for (auto c : k[digits[s.size()] - '2']) {
        // for (int i = 0; i < k[digits[s.size()] - '2'].size(); i++) {
            // s += k[digits[s.size()] - '2'][i];
            /*
            s += c;
            helper(res, digits, s);
            s.pop_back();
            */
            // tips 2 : directly dfs
            helper(res, digits, s + c);
        }
    }
};