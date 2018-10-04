class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res = M;
        int m = M.size(), n = M[0].size();
        vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int s = M[i][j], c = 1;
                for (pair<int, int> p : dirs) {
                    int mm = i + p.first, nn = j + p.second;
                    if (mm >= 0 && mm < m && nn >= 0 && nn < n) {
                        s += M[mm][nn];
                        c++;
                    }
                }
                res[i][j] = s / c;
            }
        }
        return res;
    }
};