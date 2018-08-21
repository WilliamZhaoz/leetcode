class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str, 0, str.size() - 1);
        int start = 0, end = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                end = i - 1;
                reverse(str, start, end);
                start = i + 1;
            }
        }
        reverse(str, start, str.size() - 1);
    }
    void reverse(vector<char> &str, int start, int end) {
        while (start < end) {
            str[start] ^= str[end];
            str[end] ^= str[start];
            str[start] ^= str[end];
            start++;
            end--;
        }
    }
};