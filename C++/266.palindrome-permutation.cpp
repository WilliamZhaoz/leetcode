class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int>m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        int oddc = 0;
        for (auto pair : m) {
            oddc += pair.second % 2;
        }
        return (oddc == 1 && s.size() % 2) || (s.size() % 2 == 0 && oddc == 0);
    }
};