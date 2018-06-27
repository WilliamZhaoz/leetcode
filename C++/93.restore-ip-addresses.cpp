// version 1 devide by point
/*
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12 || s.size() < 4) {
            return res;
        }
        helper(res, s, 0, 1);
        return res;
    }
    void helper(vector<string> &res, string s, int n, int start) {
        if (n == 3) {
            if (valid(s)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = start; i < s.size(); i++) {
            s.insert(i, ".");
            helper(res, s, n + 1, i + 2);
            s.erase(i, 1);
        }
    }
    bool valid(string s) {
        int tmp = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                tmp = 0;
                continue;
            }
            if (s[i] == '0' && tmp == 0 && i + 1 < s.size() && s[i + 1] != '.') {
                return false;
            }
            tmp = tmp * 10 + s[i] - '0';
            if (tmp > 255) {
                return false;
            }
        }
        return true;
    }
};
*/
// version 2
/*
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12 || s.size() < 4) {
            return res;
        }
        string ip;
        helper(res, s, ip, 0, 0);
        return res;
    }
    void helper(vector<string> &res, string s, string ip, int n, int start) {
        if (n == 4 && start == s.size()) {
        // if (n == 4 && ip.size() == s.size() + 4) {
            ip.pop_back();
            res.push_back(ip);
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (start + i - 1 > s.size() - 1 || !valid(s.substr(start, i))) {
                return;
            }
            ip.append(s.substr(start, i).append("."));
            helper(res, s, ip, n + 1, start + i);
            ip = ip.substr(0, ip.size() - 1 - i);   
        }
    }
    bool valid(string s) {
        if (s[0] == '0') {
            return s == "0";
        }
        int tmp = stoi(s);
        return tmp <= 255;
    }
};
*/
// version 3 for loop directly
class Solution {
public:
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