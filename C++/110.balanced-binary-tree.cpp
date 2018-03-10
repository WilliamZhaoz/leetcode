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
    int getDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return isBalanced(root->left) && isBalanced(root->right) && abs(left - right) <= 1;
    }
};