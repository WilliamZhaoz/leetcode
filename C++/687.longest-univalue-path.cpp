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
    int res = 0;
    int dfs(TreeNode* root, int val) {
        if (!root || root->val != val) {
            return 0;
        }
        return 1 + max(dfs(root->left, val), dfs(root->right, val));
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, dfs(root->left, root->val) + dfs(root->right, root->val));
    }
};