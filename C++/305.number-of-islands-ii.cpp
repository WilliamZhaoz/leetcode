

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
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		UnionFind uf(0, m * n);
        vector<vector<char>> grid(m, vector<char>(n, '0'));
        vector<int> res;
        if (m == 0 || n == 0) {
			return res;
		}
        for (auto pos : positions) {
            int i = pos.first, j = pos.second;
            grid[i][j] = '1';
            uf.set_count(uf.get_count() + 1);
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
            res.push_back(uf.get_count());
        }
        return res;
	}
};