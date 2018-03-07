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
    
    // version 1 : marker NULL
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
    
    // version 2 : for loop
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
};