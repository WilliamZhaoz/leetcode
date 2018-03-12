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
    int res;
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        res = max(res, l + r + root->val);
        return max(0, max(l, r) + root->val);
    }
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        res = root->val;
        dfs(root);
        return res;
    }
};