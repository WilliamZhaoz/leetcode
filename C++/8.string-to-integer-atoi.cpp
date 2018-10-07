class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        if (str.empty()) {
            return res;
        }
        int tag = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                continue;
            }
            if (!tag && str[i] == '-') {
                tag = -1;
                continue;
            }
            if (!tag && str[i] == '+') {
                tag = 1;
                continue;
            }
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            res = res * 10 + str[i] - '0';
        }
        res = tag == -1 ? -res : res;
        if (res > INT_MAX) {
            res = INT_MAX;
        }
        if (res < INT_MIN) {
            res = INT_MIN;
        }
        return res;
        
    }
};