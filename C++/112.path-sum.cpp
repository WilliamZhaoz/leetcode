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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
           return false;
        } 
        if (!root->left && !root->right && root->val == sum) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    */
    
    // non-recursive version
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        stack<TreeNode*> s; 
        TreeNode* node = root;
        while (!s.empty() || node) {
            if (node) {
                if (!node->left && !node->right && node->val == sum) {
                    return true;
                }
                s.push(node);
                if (node->left) {
                    node->left->val += node->val;
                }
                node = node->left;
            } else {
                if (s.top()->right) {
                    s.top()->right->val += s.top()->val;
                }
                node = s.top()->right;
                s.pop();
            } 
        }
        return false;
    }
};