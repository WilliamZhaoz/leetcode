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
    1. level.insert(level.begin(), 1, node->val)
    2. level[qs - 1 - i] = node->val
    3. reverse(level.begin(), level.end())
    4. vector<int>(level.rbegin(), level.level.rend())
    */
    
    // version 1 : bfs marker NULL
    /*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int tag = 0; // bool l2r  !l2r
        vector<int> level;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                res.push_back(level);
                level.clear();
                tag ++;
                if (!q.empty()) {
                    q.push(NULL);   
                }
            } else {
                if (tag % 2) {
                    level.push_back(node->val); 
                } else {
                    level.insert(level.begin(), 1, node->val);
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                } 
            }
        }
        return res;
    }
    */
    
    // version 2 : bfs for loop
    /*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) {
            return res;
        }
        q.push(root);
        int tag = 0;
        while (!q.empty()) {
            int qs = q.size();
            vector<int> level;
            for (int i = 0; i < qs; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (!(tag % 2)) {
                    level.push_back(node->val); // level[i] = 
                } else {
                    level.insert(level.begin(), 1, node->val); // level[qs - 1 - i] = 
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
            tag++;
        }
        return res;
    }
    */
    
    // version 3 : dfs
    vector<vector<int>> res;
    void dfs(TreeNode* root, int depth) {
        if (!root) {
           return; 
        }
        if(res.size() == depth) {
            res.push_back(vector<int>());
        }
        if (depth % 2) {
            res[depth].insert(res[depth].begin(), 1, root->val);
        } else {
            res[depth].push_back(root->val);    
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};