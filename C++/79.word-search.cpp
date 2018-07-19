
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
