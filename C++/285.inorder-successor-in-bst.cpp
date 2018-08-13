/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// version 1: recursive
/*
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) {
            return NULL;
        }
        if (root->val > p->val) {
            TreeNode *left = inorderSuccessor(root->left, p);
            return left ? left : root;
        } else {
            return inorderSuccessor(root->right, p);
        }
    }
};
*/
// version 2: non-recursive
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) {
            return NULL;
        }
        TreeNode *res = NULL;
        while (root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return res;
    }
};
// version 3: inorder traversal