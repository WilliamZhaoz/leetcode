class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0, n = letters.size(), end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (letters[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (letters[start] > target) {
            return letters[start];
        }
        if (letters[end] > target) {
            return letters[end];
        }
        return letters[0];
    }
};