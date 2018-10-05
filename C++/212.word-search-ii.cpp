// version 1 : brute force + backtracking, TLE
/*
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        for (int i = 0; i < words.size(); i++) {
            if (exist(board, words[i])) {
                res.insert(words[i]);
            }
        }
        vector<string> resv;
        for (auto s : res) {
            resv.push_back(s);
        }
        return resv;
    }
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
*/
// version 2 : trie tree, store the words
/*
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode(): word("") {
            for (auto &c : children) {
                c = NULL;
            }
        }
        
    };
    struct Trie {
        TrieNode *root;
        Trie(): root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto c : s) {
                int i = c - 'a';
                if (!p->children[i]) {
                    p->children[i] = new TrieNode();
                }
                p = p->children[i];
            }
            p->word = s;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty()) {
            return res;
        }
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        Trie trie;
        for (auto word : words) {
            trie.insert(word);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(board, visited, res, i, j, trie.root);
            }
        }
        return res;
    }
    void helper(vector<vector<char>> &board, vector<vector<bool>> &visited, vector<string> &res, int i, int j, TrieNode* p) {
        if (!p->word.empty()) {
            res.push_back(p->word);
            p->word.clear();
        }
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = board.size(), n = board[0].size();
        for (auto dir : dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            if (i >= 0 && i < m && j >= 0 && j < n && p->children[board[i][j] - 'a'] && !visited[i][j]) {
                visited[i][j] = true;
                helper(board, visited, res, ni, nj, p->children[board[i][j] - 'a']);
                visited[i][j] = false;
            }
        }
    }
};
*/
// version 3 : trie tree, store the board, TLE
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode(): word("") {
            for (auto &c : children) {
                c = NULL;
            }
        }
    };
    struct Trie {
        TrieNode* root;
        Trie(): root(new TrieNode()){};
        void insert(string s) {
            TrieNode *p = root;
            for (auto c : s) {
                int i = c - 'a';
                if (!p->children[i]) {
                    p->children[i] = new TrieNode();
                }
                p = p->children[i];
            }
            p->word = s;
        }
        bool find(string s) {
            TrieNode *p = root;
            for(auto c : s) {
                int i = c - 'a';
                if (!p->children[i]) {
                    return false;
                }
                p = p->children[i];
            }
            if (p->word.empty()) {
                return false;
            }
            p->word.clear();
            return true;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) {
            return res;
        }
        int m = board.size(), n = board[0].size();
        Trie trie;
        string cur = "";
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(board, visited, i, j, cur, trie);
            }
        }
        for (auto word : words) {
            if (trie.find(word)) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, string &cur, Trie &trie) {
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int m = board.size(), n = board[0].size();
        for (auto dir : dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]) {
                visited[i][j] = true;
                cur += board[i][j];
                trie.insert(cur);
                helper(board, visited, ni, nj, cur, trie);
                cur.pop_back();
                visited[i][j] = false;
            }
        }
    }
   
};