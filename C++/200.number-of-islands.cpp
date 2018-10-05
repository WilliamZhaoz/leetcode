// version 1 : union find
/*
class UnionFind {
private:
	unordered_map<int, int> fatherMap;
	int count;
public:
	int find_(int x) {
		int father = fatherMap[x];
		while (father != fatherMap[father]) {
			father = fatherMap[father];
		}
		return father;
	}
	void union_(int x, int y) {
		int x_root = find_(x), y_root = find_(y);
		if (x_root != y_root) {
			count--;
			fatherMap[x_root] = y_root;
		}
	}
	int find_compressed(int x) {
		int father = fatherMap[x];
		while (father != fatherMap[father]) {
			father = fatherMap[father];
		}
		int next;
		while (x != fatherMap[x]) {
			next = fatherMap[x];
			fatherMap[x] = father;
			x = next;
		}
		return father;

	}
	void set_count(int c) {
		count = c;
	}
	int get_count() {
		return count;
	}
	UnionFind(){};
	UnionFind(int c, int n) {
		count = c;
		for (int i = 0; i < n; i++) {
			fatherMap[i] = i;
		}
	};
};
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int m = grid.size(), n = grid[0].size(), res = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					// fatherMap[i * n + j] = i * n + j;
					res++;
				}

			}
		}
		UnionFind uf(res, m * n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					if (i + 1 < m && grid[i + 1][j] == '1') {
						uf.union_(i * n + j, (i + 1) * n + j);
					}
					if (j + 1 < n && grid[i][j + 1] == '1') {
						uf.union_(i * n + j, i * n + j + 1);
					}
					if (i - 1 >= 0 && grid[i - 1][j] == '1') {
						uf.union_(i * n + j, (i - 1) * n + j);
					}
					if (j - 1 >= 0 && grid[i][j - 1] == '1') {
						uf.union_(i * n + j, i * n + j - 1);
					}
				}
			}
		}
		return uf.get_count();
	}
};
*/
// version 2 : dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    helper(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void helper(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int m = grid.size(), n = grid[0].size();
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d].first, nj = j + dirs[d].second;
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && !visited[ni][nj] && grid[i][j] == '1') {
                visited[ni][nj] = true;
                helper(grid, visited, ni, nj);
            }
        }
    }
    
};
