class Solution {
public:
    // version 1 : recursive
    /*
    vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = 0;
                helper(grid, i, j, tmp, res);
            }
        } 
        return res;
    }
    void helper(vector<vector<int>> &grid, int i, int j, int &tmp, int &res) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] <= 0) {
            return;
        }
        grid[i][j]--;
        res = max(res, ++tmp);
        for (auto d : dir) {
            helper(grid, i + d.first, j + d.second, tmp, res);
        }
    }
    */
    vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size(), res = 0, tmp = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                queue<pair<int, int>> q;
                q.push(pair<int, int>(i, j));
                tmp = 0;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    int ii = p.first, jj = p.second;
                    if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] > 0) {
                        res = max(res, ++tmp);
                        grid[ii][jj]--;
                        for (auto d : dir) {
                            q.push(pair<int, int>(ii + d.first, jj + d.second));
                        }    
                    }
                    
                }
            }
        }
        return res;
    }
    
};