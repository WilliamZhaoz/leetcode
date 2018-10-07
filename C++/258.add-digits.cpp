class Solution {
public:
    int addDigits(int num) {
        // version 1 : 2 loop
        // version 2:
        return (num - 1) % 9 + 1;
    }
};