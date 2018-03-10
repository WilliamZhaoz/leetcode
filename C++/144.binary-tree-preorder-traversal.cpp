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
    // recursive version
    /*
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return res;
        }
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
    */
    
    /*
    // non-recursive version 1
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()) {
            if (node) {
                res.push_back(node->val);
                s.push(node);
                node = node->left;
            } else {
                node = s.top()->right;
                s.pop();
            }
        }
        return res;
    }
    */
    
    // non-recursive version 2
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        if (!root) {
            return res;
        }
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop(); 
            res.push_back(node->val);
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }
        return res;
    }
    
};