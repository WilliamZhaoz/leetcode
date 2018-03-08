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
    
    // version 1 : bfs marker NULL
    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) {
            return res;
        }
        q.push(root);
        q.push(NULL);
        vector<int> level_v;
        while (!q.empty()) {
            TreeNode * node = q.front();
            q.pop();
            if (!node) {
                res.push_back(level_v);
                level_v.resize(0); // level_v.clear()
                if (q.size() > 0) {
                    q.push(NULL);    
                }  
            } else {
                level_v.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
    */
    
    // version 2 : bfs for loop
    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            vector<int> level_vec;
            int qs = q.size(); // necessary
            for (int i = 0; i < qs; i++) {
                TreeNode* node = q.front();
                level_vec.push_back(node->val);
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level_vec);
        }
        return res;
    }
    */
    
    // version 3 : dfs
    vector<vector<int>> res;
    void dfs (TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        if (res.size() == depth) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};