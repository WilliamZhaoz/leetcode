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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int &res) {
        if (!root) {
            return -1;
        }
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        res = max(res, left + right + 2);
        return max(left, right) + 1;
    }
};