class Solution {
public:
    // version 1 : brute force + hash map
    /*
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++) {
            if (m.count(words[i])) {
                res += m[words[i]];
                continue;
            }
            if (issub(S, words[i])) {
                res++;
                m[words[i]]++;
            } else {
                m[words[i]] = 0;
            }
        }
        return res;
    }
    bool issub(string s, string word) {
        int sp = 0, wp = 0, sl = s.size(), wl = word.size();
        while (sp < sl && wp < wl) {
            if (s[sp++] == word[wp]) {
                wp++;
            }
        }
        return wp == wl;
    }
    */
    // version 2 :
    int numMatchingSubseq(string S, vector<string>& words) {
        
    }
};