class Solution {
public:
    string convertToTitle(int n) {
        // version 1 : my version
        /*
        string res = "";
        while (n) {
            if (n % 26) {
                res = string(1, n % 26 - 1 + 'A') + res;
            } else {
                res = string(1, 'Z') + res;
                n -= 1;
            }
            n /= 26;
        }
        return res;
        */
        // version 2:
        string res = "";
        while (n) {
            res = string(1, --n % 26 + 'A') + res;
            n /= 26;
        }
        return res;
    }
};