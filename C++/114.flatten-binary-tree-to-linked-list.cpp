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
    void flatten(TreeNode* root) {
        // version 1 : dfs recursive
        /*
        if (!root) {
            return;   
        }        
        flatten(root->left);
        flatten(root->right);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) {
            root = root->right;
        }
        root->right = tmp;
        */
        // version 2 : dfs non-recursive
        /*
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* p = cur->left;
                while (p->right) {
                    p = p->right;
                }
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
        */
        // version 3 : dfs non-recursive preorder traversal
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top(); s.pop();
            if (t->left) {
                TreeNode *r = t->left;
                while (r->right) {
                    r = r->right;
                }
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }
            if (t->right) {
                s.push(t->right);
            }
        }
    }
};