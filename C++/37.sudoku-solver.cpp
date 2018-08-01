// version 1:
/*
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) {
			return;
		}
		vector<unordered_set<char>> row(9, unordered_set<char>());
		vector<unordered_set<char>> col(9, unordered_set<char>());
		vector<unordered_set<char>> blo(9, unordered_set<char>());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                isValidSudoku(row, col, blo, i, j, board[i][j]);
            }
        }
        helper(board, row, col, blo, 0);
        return;
    }
    bool helper(vector<vector<char>> &board, vector<unordered_set<char>> &row, vector<unordered_set<char>> &col, vector<unordered_set<char>> &blo, int pos) {
        if (pos == 81) {
            return true;
        }  
        int r = pos / 9, c = pos % 9;
        int b = r / 3 * 3 + c / 3;
        if (board[r][c] != '.') {
            return helper(board, row, col, blo, pos + 1);
        }
        for (int i = 1; i <= 9; i++) {    
            char element = to_string(i)[0];
            if (isValidSudoku(row, col, blo, r, c, element)) {
                board[r][c] = element;
                
                if (helper(board, row, col, blo, pos + 1)) {
                    return true;
                }
                row[r].erase(element);
                col[c].erase(element);
                blo[b].erase(element);
                board[r][c] = '.';
            }
        }
        return false;
    }
    bool isValidSudoku(vector<unordered_set<char>> &row, vector<unordered_set<char>> &col, vector<unordered_set<char>> &blo, int i, int j, char c) {
        if (c == '.') {
            return false;
        }
		int blo_n = i / 3 * 3 + j / 3;
		if (row[i].count(c) || col[j].count(c) || blo[blo_n].count(c)) {
			return false;
		}
		else {
			row[i].insert(c);
			col[j].insert(c);
			blo[blo_n].insert(c);
		}
		return true;
	}
};
*/
// version 2:
class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board, vector<int>& row, vector<int>& col, vector<int>& squ) {
        if (y == 9) {
            x++;
            y = 0;
        }
        if (x == 9)
            return true;
        if (board[x][y] != '.') {
            return (dfs(x, y + 1, board, row, col, squ));
        }
        for (int i = 1; i <= 9; i++) {
            if (!((row[x] & (1 << i)) || (col[y] & (1 << i)) || (squ[(x / 3) * 3 + (y / 3)] & (1 << i)))) {
                row[x] |= (1 << i);
                col[y] |= (1 << i);
                squ[(x / 3) * 3 + (y / 3)] |= (1 << i);
                board[x][y] = i + '0';
                if(dfs(x, y + 1, board, row, col, squ)) {
                    return true;
                }
                board[x][y] = '.';
                row[x] -= (1 << i);
                col[y] -= (1 << i);
                squ[(x / 3) * 3 + (y / 3)] -= (1 << i);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9), col(9), squ(9);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                row[i] |= (1 << num);
                col[j] |= (1 << num);
                squ[(i / 3) * 3 + (j / 3)] |= (1 << num);
            }
        dfs(0, 0, board, row, col, squ);
    }
};

