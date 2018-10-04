class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int left = 1, right = n;
        while (left <= right) {
            if (k > 1) {
                res.push_back(k-- % 2 ? right-- : left++);
            } else {
                res.push_back(right--);
            }
        }
        return res;
    }
};