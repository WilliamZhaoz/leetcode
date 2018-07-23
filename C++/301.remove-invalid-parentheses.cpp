// version 1: 1) backtracking the char to delet
//            2) once find the valid string, continue, to guarantee that remove the minimum number.
//            3) use hash table to drop duplicate.
/*
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q{{s}};
        unordered_set<string> h{{s}};
        bool f = false;
        while (!q.empty()) {
            string t = q.front(); 
            q.pop();
            if (isValid(t)) {
                res.push_back(t);
                h.insert(t);
                f = true;
            }
            if (f) {
                continue;
            }
            for (int i = 0; i < t.size(); i++) {
                if (t[i] != '(' && t[i] != ')') {
                    continue;
                }
                string tt = t.substr(0, i) + t.substr(i + 1);
                if (h.count(tt) == 0) {
                    h.insert(tt);
                    q.push(tt);
                } 
            }
        }
        return res;
    }
    bool isValid(string s) {
        int lc = 0;
        for (auto c : s) {
            if (lc < 0) {
                return false;
            }
            lc += c == '(' ? 1 : c == ')' ? -1 : 0;
        }
        return lc == 0;
    }
};
*/
// version 2: 1) count the extra ( or )
//            2) delete the extra ( or )
//            3) continue if there are consecutive ( or )
//            4) got the result if extra ( and ) are both zero.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int cl = 0, cr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cl++;
            } else if (s[i] == ')') {
                if (cl > 0) {
                    cl--;
                } else {
                    cr++;
                }
            }
        }
        helper(res, s, 0, cl, cr);
        return res;
    }
    void helper(vector<string> &res, string s, int start, int cl, int cr) {
        if (cl == 0 && cr == 0) {
            if (isValid(s)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[i - 1]) {
                continue;
            }
            if (cl > 0 && s[i] == '(') {
                helper(res, s.substr(0, i) + s.substr(i + 1), i, cl - 1, cr);
            }
            if (cr > 0 && s[i] == ')') {
                helper(res, s.substr(0, i) + s.substr(i + 1), i, cl, cr - 1);
            }
        }
    }
    bool isValid(string s) {
        int lc = 0;
        for (auto c : s) {
            if (lc < 0) {
                return false;
            }
            lc += c == '(' ? 1 : c == ')' ? -1 : 0;
        }
        return lc == 0;
    }
};