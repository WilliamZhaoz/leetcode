class Solution {
public:
    // version 1: 
    /*
    
    string numberToWords(int num) {
        if (!num) {
            return "Zero";
        }
        int billions = num / 1000000000;
        int millions = num % 1000000000 / 1000000;
        int thousands = num % 1000000 / 1000;
        int tails = num % 1000;
        string res = helper(3, billions) + helper(2, millions) + helper(1, thousands) + helper(0, tails);
        if (res[res.size() - 1] == ' ') {
            res.erase(res.size() - 1, 1);
        }
        return res.substr(1, res.size() - 1);
    }
    string helper(int base_i, int num) {
        vector<string> base{"", "Thousand", "Million", "Billion"};
        string pre = "";
        if (!num) {
            return "";
        }
        if (num < 100) {
            pre = helper2(num);
        } else {
            int h = num / 100;
            int d = num % 100;
            pre = helper2(h) + " Hundred" + (helper2(d) == "" ? "" : " " + helper2(d));
        }
        return " " + pre + " " + base[base_i];
    }
    string helper2(int num) {
        vector<string> singleDigit{"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> dozens{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if (!num) {
            return "";
        }
        string res = "";
        if (num < 20) {
            res = singleDigit[num - 1];
        } else if (num < 100) {
            int d = num % 10;
            res = dozens[num / 10 - 2] + (!d ? "" : " " + singleDigit[d - 1]);
        }
        return res;
    }
    */
    // version 2: 
    /*
    string numberToWords(int num) {
        if (!num) {
            return "Zero";
        }
        int billions = num / 1000000000;
        int millions = num % 1000000000 / 1000000;
        int thousands = num % 1000000 / 1000;
        int tails = num % 1000;
        string res = helper(4, billions) + helper(3, millions) + helper(2, thousands) + helper(0, tails);
        return trim(res);
    }
    string helper(int base_i, int num) {
         vector<string> singleDigit{"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> dozens{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> base{"", "Hundred", "Thousand", "Million", "Billion"};
        string pre = "";
        if (!num) {
            return "";
        }
        if (num < 20) {
            pre = singleDigit[num - 1];
        } else if (num < 100) {
            int d = num % 10;
            pre = dozens[num / 10 - 2] + " " + singleDigit[d - 1];
        } else {
            int h = num / 100;
            int d = num % 100;
            pre = helper(1, h) + helper(0, d);
        }
        return " " + pre + " " + base[base_i]; 
    }
    string trim(string res) {
        for (int i = 0; i < res.size(); i++) {
            if (i == 0 && res[i] == ' ') {
                res.erase(0, 1);
                i--;
            }
            if (i < res.size() - 1 && res[i] == ' ' && res[i + 1] == ' ') {
                res.erase(i + 1, 1);
                i--;
            }
            if (i == res.size() - 1 && res[i] == ' ') {
                res.erase(res.size() - 1, 1);
                i--;
            }
        }
        return res;
    }
    */
    // version 3
    string numberToWords(int num) {
        string res = convertHundred(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
        }
        while (res.back() == ' ') res.pop_back();
        return res.empty() ? "Zero" : res;
    }
    string convertHundred(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
        if (a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
        return res;
    }
};