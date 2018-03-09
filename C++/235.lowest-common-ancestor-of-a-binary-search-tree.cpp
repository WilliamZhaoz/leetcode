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
    // version 1 : recursive
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > max(q->val, p->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < min(q->val, p->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    */
    
    // version 2 : while loop
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while ((root->val - q->val) * (root->val - p->val) > 0) {
            root = root->val > q->val ? root->left : root->right;
        }
        return root;
    }
    
};