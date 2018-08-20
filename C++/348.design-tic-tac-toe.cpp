// version 1:

class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> map;
    vector<int> row_v;
    vector<int> col_v;
    int dia = 0;
    int arcdia = 0;
    TicTacToe(int n) {
        map = vector<vector<int>>(n, vector<int>(n, 0));
        row_v = vector<int>(n, 0);
        col_v = vector<int>(n, 0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        map[row][col] = player;
        row_v[row] += player == 1 ? 1 : -1;
        col_v[col] += player == 1 ? 1 : -1;
        if (row == col) {
            dia += player == 1 ? 1 : -1;
        }
        if (row == row_v.size() - 1- col) {
            arcdia += player == 1 ? 1 : -1;
        }
        if (row_v[row] == row_v.size() || col_v[col] == row_v.size() || dia == row_v.size() || arcdia == row_v.size()) {
            return 1;
        }
        if (row_v[row] == -row_v.size() || col_v[col] == -row_v.size() || dia == -row_v.size() || arcdia == -row_v.size()) {
            return 2;
        }
        return 0;
    }
};


/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

// version 2:
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): rows(n), cols(n), N(n), diag(0), rev_diag(0) {}

    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rows[row] += add; 
        cols[col] += add;
        diag += (row == col ? add : 0);
        rev_diag += (row == N - col - 1 ? add : 0);
        return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N || abs(rev_diag) == N) ? player : 0;
    }

private:
    vector<int> rows, cols;
    int diag, rev_diag, N;
};
