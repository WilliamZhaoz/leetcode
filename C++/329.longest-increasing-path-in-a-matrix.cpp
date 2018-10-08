class Solution {
public:
    // version 1 : dfs + back tracking + mrmoization TLE, but I do not know why
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int res = 1, cur = 1, curm = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                curm = 1;
                helper(matrix, dp, res, curm, cur, i, j);
                dp[i][j] = curm;
            }
        }
        return res;
    }
    void helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int &res, int &curm, int cur, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d].first, nj = j + dirs[d].second;
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && matrix[i][j] < matrix[ni][nj]) {
                if (dp[ni][nj]) {
                    curm = max(curm, cur + dp[ni][nj]);
                    continue;
                }
                curm = max(curm, cur + 1);
                helper(matrix, dp, res, curm, cur + 1, ni, nj);
            }
            
        }
        res = max(res, curm);

    }
    
    /*
    // version 2 : dfs + back tracking + mrmoization  accepted
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (auto a : dirs) {
            int x = i + a[0], y = j + a[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(matrix, dp, x, y);
            mx = max(mx, len);
        }
        dp[i][j] = mx;
        return mx;
    }
    */
    // version 2 : topological sort, base edges
    /*
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> es;
        unordered_map<int, int> in;
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto dir : dirs) {
                    int ni = i + dir.first, nj = j + dir.second, id = i * n + j, nid = ni * n + nj;
                    if (ni >= 0 && nj >= 0 && ni < m && nj < n && matrix[ni][nj] > matrix[i][j]) {
                        es.push_back(pair<int, int>{id, nid});
                        in[nid]++;
                    }
                }
            }
        }
        unordered_map<int, int> intmp = in;
        while (!es.empty()) {
            intmp = in;
            for (int i = 0; i < es.size(); i++) {
                if (in.count(es[i].first) == 0) {
                    intmp[es[i].second]--;
                    if (intmp[es[i].second] == 0) {
                        intmp.erase(es[i].second);
                    }
                    es.erase(es.begin() + i--);
                }
            }
            in = intmp;
            res++;
            
        }
        return res;
    }
    */
    
};
