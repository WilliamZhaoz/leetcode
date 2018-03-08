/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    /*
    reverse function 
    1. res.insert(res.begin(), 1, level)
    2. reverse(res.begin(), res.end());
    3. vector<vector<int>> (res.rbegin(), res.rend())
    4. res[index] = level
    */
    
    // version 1 : bfs marker NULL
    
    /*
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) {
            return res;
        }
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                res.push_back(level);
                level.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
        }
        reverse(res.begin(), res.end());
        return res; // return vector<vector<int>> (res.rbegin(), res.rend());
    }
    */
    
    // version 2 : bfs for loop
    
    /*
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            //TreeNode *node = q.front();
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                TreeNode *node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    */
    
    // version 3 : dfs
    void dfs(TreeNode* root, vector<vector<int>> &res, int depth) {
        if (!root) {
            return;
        }
        if (res.size() <= depth) {
            res.push_back(vector<int>());
        } 
        dfs(root->left, res, depth + 1);
        dfs(root->right, res, depth + 1);
        res[depth].push_back(root->val);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};