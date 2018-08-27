class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // version 1 : force brute
        /*
        unordered_map<string, int> m;
        vector<string> res;
        if (s.size() <= 10) {
            return res;
        }
        for (int i = 0; i < s.size() - 9; i++) {
            string tmp = s.substr(i, 10);
            if (m[tmp] == 1) {
                res.push_back(tmp);
                m[tmp] = -1;
            } else if (m[tmp] == 0) {
                m[tmp]++;
            }
        }
        return res;
        */
        // version 2 : force brute, use 2 set
        /*
        unordered_set<string> set, res;
        for (int i = 0; i < int(s.size() - 9); i++) {
            string tmp = s.substr(i, 10);
            if (set.count(tmp)) {
                res.insert(tmp);
            }
            set.insert(tmp);
        }
        return vector<string>(res.begin(), res.end());
        */
        // version 3 : bit manipulation
        unordered_map<char, string> map{{'A', "00"}, {'C', "01"}, {'G', "10"}, {'T', "11"}};
        string ss;
        for (int i = 0; i < s.size(); i++) {
            ss += map[s[i]];
        }
        unordered_set<bitset<20>> set;
        unordered_set<string> res;
        for (int i = 0; i < int(s.size() - 9); i++) {
            string tmps = s.substr(i, 10);
            string tmpss = ss.substr(i * 2, 20);
            bitset<20> tmpbs = bitset<20>(tmpss);
            if (set.count(tmpbs)) {
                res.insert(tmps);
            } else {
                set.insert(tmpbs);
            }
        }
        return vector<string>(res.begin(), res.end());
        
    }
};