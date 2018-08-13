class Solution {
public:
    // version 1
    bool isOneEditDistance(string s, string t) {
        if (abs((int)s.size() - (int)t.size()) > 1) {
            return false;
        }
        for (int i = 0; i < min(s.size(), t.size()); i++) {
            if (t[i] != s[i]) {
                return s.size() == t.size() ? t.substr(i + 1) == s.substr(i + 1) : t.size() > s.size() ? t.substr(i + 1) == s.substr(i) : t.substr(i) == s.substr(i + 1);     
                /*
                if (s.size() == t.size()) return s.substr(i + 1) == t.substr(i + 1);
                else if (s.size() < t.size()) return s.substr(i) == t.substr(i + 1);
                else return s.substr(i + 1) == t.substr(i);
                */
            }
        }
        return s != t;
    }
    // version 2: 1). length_diff > 1. 
    //            2). length_diff == 1 
    //            3). length_diff == 0 
};