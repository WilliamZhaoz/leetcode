class Solution {
public:
    // version 1
    /*
    string addStrings(string num1, string num2) {
        string res = "";
        int l1 = num1.size() - 1, l2 = num2.size() - 1;
        int tmp = 0;
        while (l1 >= 0 && l2 >= 0) {
            int cur = tmp + num1[l1] - '0' + num2[l2] - '0';
            if (cur >= 10) {
                tmp = 1;
                cur -= 10;
            } else {
                tmp = 0;
            }
            res = to_string(cur) + res;
            l1--;
            l2--;
        }
        while (l1 >= 0) {
            int cur = tmp + num1[l1] - '0';
            if (cur >= 10) {
                tmp = 1;
                cur -= 10;
            } else {
                tmp = 0;
            }
            res = to_string(cur) + res;
            l1--;
        }
        while (l2 >= 0) {
            int cur = tmp + num2[l2] - '0';
            if (cur >= 10) {
                tmp = 1;
                cur -= 10;
            } else {
                tmp = 0;
            }
            res = to_string(cur) + res;
            l2--;
        }
        if (tmp) {
            res = "1" + res;
        }
        return res;
    }
    */
    // version 2:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = num1.size(), n = num2.size(), i = m - 1, j = n - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int sum = a + b + carry;
            res.insert(res.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        return carry ? "1" + res : res;
    }
};