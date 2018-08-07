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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int &res) {
        if (!root) {
            return INT_MIN;
        }
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        /*
        int passroot = max(0, left) + max(0, right) + root->val;
        res = max(res, max(passroot, max(left, right)));
        */
        res = max(res, max(0, left) + max(0, right) + root->val);
        return max(0, max(left, right)) + root->val;
    }
};