class Solution {
public:
    // store borders
    // find the shorter
    // traversal the shorter's neighbors
    // update the borders and the shorter
    
    // need to use min heap to find the shorter quickly
    // reference : https://www.cnblogs.com/grandyang/p/5928987.html
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int res = 0, shorter = 0, m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> dir({{0, -1}, {0, 1}, {-1, 0}, {1, 0}});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    visited[i][j] = 1;
                    q.push({heightMap[i][j], {i, j}});
                }
            }
        }
        while (!q.empty()) {
            auto tmp = q.top(); q.pop();
            int h = tmp.first, x = tmp.second.first, y = tmp.second.second;
            shorter = max(shorter, h);
            for (int i = 0; i < dir.size(); i++) {
                int xx = x + dir[i][0], yy = y + dir[i][1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || visited[xx][yy] == 1) continue;
                visited[xx][yy] = 1;
                if (heightMap[xx][yy] < shorter) res += shorter - heightMap[xx][yy];
                q.push({heightMap[xx][yy], {xx, yy}});
            }
        }
        return res;
    }
};