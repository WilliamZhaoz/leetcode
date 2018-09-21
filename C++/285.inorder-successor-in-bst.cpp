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
// version 3: recursive inorder traversal

class Solution {
public:
    bool b = false, bb = false;
    TreeNode *successor = NULL;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        helper(root, p);
        return successor;
    }
    void helper(TreeNode* root, TreeNode*p) {
        if (!p || !root) {
            return;
        }
        inorderSuccessor(root->left, p);
        if (b && !bb) {
            successor = root;
            bb = true;
        }
        if (p == root) {
            b = true;
        }
        inorderSuccessor(root->right, p);
    }
};

// version 4: non-recursive inorder traversal

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) {
            return NULL;
        }
        stack<TreeNode*> s;
        TreeNode *node = root;
        bool b = false;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                if (b) {
                    return s.top();
                }
                if (s.top() == p) {
                    b = true;
                }
                node = s.top()->right;
                s.pop();
            }
            
        }
        return NULL;
    }
};