
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (helper(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        } 
        return false;
    }
    bool helper(vector<vector<char>> &board, string word, int index, int i, int j, vector<vector<bool>> &visited) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }
        visited[i][j] = true;
        bool res = helper(board, word, index + 1, i + 1, j, visited)
            || helper(board, word, index + 1, i - 1, j, visited)
            || helper(board, word, index + 1, i, j + 1, visited)
            || helper(board, word, index + 1, i, j - 1, visited);
        visited[i][j] = false;
        return res;
    }
};
// version : 10/5/2018
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return true;
        }
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (helper(board, visited, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int start, int i, int j) {
        if (start == word.size()) {
            return true;
        }
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int m = board.size(), n = board[0].size();
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d].first, nj = j + dirs[d].second;
            if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j] && board[i][j] == word[start]) {
                visited[i][j] = true;
                if (helper(board, visited, word, start + 1, ni, nj)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }
};