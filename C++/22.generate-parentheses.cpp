/*
// memory limit exceede 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string com;
        if (n < 1) {
            return res;
        }
        helper(res, com, n, 0, true);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    void helper(vector<string> &res, string &com, int n, int start, bool insertleft) {
        if (com.size() == 2 * n) {
            res.push_back(com);
            return;
        }
        for (int i = start; i <= com.size(); i++) {
            char toinsert = insertleft ? '(': ')';
            start = insertleft ? i + 1 : 0;
            com.insert(com.begin() + i, toinsert);
            helper(res, com, n, start, !insertleft);
            com.erase (com.begin() + i);
        }
    }
};
*/
// version 1
/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};
*/
// version 2
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> t;
        if (n == 0) t.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (auto a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        t.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
                    }
                }
                t.insert("()" + a);
            }
        }
        return vector<string>(t.begin(), t.end());
    }
};

// write by myself in 9/7/2018
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string par = "";
        helper(res, par, n, n);
        return res;
        
    }
    void helper(vector<string> &res, string &par, int lefttoadd, int righttoadd) {
        if (lefttoadd > righttoadd || lefttoadd < 0 || righttoadd < 0) {
            return;
        }
        if (lefttoadd == 0 && righttoadd == 0) {
            res.push_back(par);
            return;
        }
        par += "(";
        helper(res, par, lefttoadd - 1, righttoadd);
        par.pop_back();
        par += ")";
        helper(res, par, lefttoadd, righttoadd - 1);
        par.pop_back();
        return;
    }
};