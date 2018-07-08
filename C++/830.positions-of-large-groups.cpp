class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        S.push_back(S[S.size() - 1] + 1);
        int count = 1;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] == S[i - 1]) {
                count++;
            } else {
                if (count >= 3) {
                    vector<int> tmp;
                    tmp.push_back(i - count);
                    tmp.push_back(i - 1);
                    res.push_back(tmp);
                }
                count = 1;
            }
        }
        return res;
    }
};