class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int leave = n - k;
        string res = "";
        for (int i = 0; i < num.size(); i++) {
            while (k && res.back() > num[i]) {
                k--;
                res.pop_back();
            }
            res += num[i];
        }
        res.resize(leave);
        while (!res.empty() && res[0] == '0') {
            res.erase(res.begin());
        }
        return res.empty() ? "0" : res;
    }
};