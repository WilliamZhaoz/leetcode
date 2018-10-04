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
        int r = node->right ? dfs(node->right, lup) : 0; // deep the tree
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0; // result include current root
        lup = max(lup, resl + resr); // refresh the result, only in this step, two half added up
        return max(resl, resr); // all values are half
    }
};

// version 10/4/2018

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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(helper(root->left, root->val) + helper(root->right, root->val), max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }
    int helper(TreeNode* root, int &val) {
        if (!root) {
            return 0;
        }
        if (root->val == val) {
            return max(helper(root->left, val), helper(root->right, val)) + 1;
        }
        return 0;
        
    }
};