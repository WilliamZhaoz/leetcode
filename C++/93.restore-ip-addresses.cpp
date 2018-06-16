class Solution {
public:
    // version 1 : backtracking by point.
    /*
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) {
            return res;
        }
        help(s, res, 0, 1);
        return res;
    }
    void help(string s, vector<string> &res, int n, int start) {
        if (n == 3) {
            if (isIpAddress(s)) {
                res.push_back(s);    
            }
            return;
        }
        for (int i = start; i < s.size(); i++) {
            s.insert(i, ".");
            help(s, res, n + 1, i + 2);
            s.erase(i, 1);
        }
    }
    bool isIpAddress(string s) {
        int tmp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (tmp == 0 && s[i] == '0' && i + 1 < s.size() && s[i + 1] != '.') {
                return false;
            }
            if (s[i] == '.') {
                if (tmp < 0 || tmp > 255) {
                    return false;
                }
                tmp = 0;
                continue;
            }
            tmp = tmp * 10 + s[i] - '0'; 
        }
        if (tmp < 0 || tmp > 255) {
            return false;
        }
        return true;
            
    }
    */
    // version 2 : backtracking by number.
    /*
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> list;
        if (s.size() < 4 || s.size() > 12) {
            return res;
        }
        helper(res, list, s, 0);
        return res;
    }
    void helper(vector<string> &res, vector<string> &list, string s, int start) {
        if (list.size() == 4) {
            if (start != s.size()) {
                return;                       
            }
            string tmp;
            for (auto l : list) {
                tmp += l;
                tmp += '.';
            }
            tmp.erase(tmp.size() - 1, 1);
            res.push_back(tmp);
            return;
        }
        for (int i = 0; start + i < s.size() && i < 3; i++) {
            string tmp = s.substr(start, i + 1);
            if (valid(tmp)) {
                list.push_back(tmp);
                helper(res, list, s, start + i + 1);
                list.pop_back();
            }
        }
    }
    bool valid(string s) {
        if (s[0] == '0') {
            return s == "0";
        }
        int tmp = atoi(s.c_str());
        return tmp >= 0 && tmp <= 255;
    }
    */
    // version 3 : for loop directly
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    for (int l = 1; l <= 3; l++) {
                        if (i + j + k + l == s.size()) {
                            /*
                            string a(s.begin() + 0, s.begin() + i);
                            string b(s.begin() + i, s.begin() + i + j);
                            string c(s.begin() + i + j, s.begin() + i + j + k);
                            string d(s.begin() + i + j + k, s.begin() + i + j + k + l);
                            */
                            string a = s.substr(0, i);
                            string b = s.substr(i, j);
                            string c = s.substr(i + j, k);
                            string d = s.substr(i + j + k, l);
                            if (valid(a) && valid(b) && valid(c) && valid(d)) {
                                res.push_back(a + "." + b + "." + c + "." + d);
                            }
                            
                          
                        } 
                    }
                }
            }
        }
        return res;
    }
    bool valid(string s) {
        if (s.size() != 1 && s[0] == '0') {
            return false;
        }
        int tmp = 0;
        for (auto c : s) {
            tmp = tmp * 10 + c - '0';
        }
        return tmp < 256;
    }
    
    
    
};