class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && helper(s[left]) == -1) {
                left++;
            }
            while (left < right && helper(s[right]) == -1) {
                right--;
            }
            if (helper(s[left]) != helper(s[right])) {
                return false;
            }
            left++; right--;
        }
        return true;
    }
    int helper(char c) {
        int h1 = c - 'a', h2 = c - 'A';
        if (h1 >= 0 && h1 < 26) {
            return h1;
        }
        if (h2 >= 0 && h2 < 26) {
            return h2;
        }
        return -1;
    }
};