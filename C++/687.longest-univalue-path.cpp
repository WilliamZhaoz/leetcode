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
    // version 1
    /*
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
    */
    
    //version 2
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};