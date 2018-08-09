class Solution {
    // we can also use reverse() function directly 
public:
    void reverseWords(string &s) {
        trailing(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                cout<<start<<i - 1<<endl;
                start = i + 1;
            }
        }
        reverse(s, start, s.size() - 1);
    }
    void reverse(string &s, int start, int end) {
        for (; start < end; start++, end--) {
            s[start] ^= s[end];
            s[end] ^= s[start];
            s[start] ^= s[end];
        }
    }
    void trailing(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && (i == 0 || i == s.size() - 1 || (s[i + 1] == ' '))) {
                s = s.erase(i, 1);
                i--;
            }
        }
    }
};