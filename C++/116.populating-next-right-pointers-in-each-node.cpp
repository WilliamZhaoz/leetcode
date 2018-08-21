/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // version 1 : recursive dfs, with extra space
    /*
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (root->left) {
            root->left->next = root->right;
        }
        if (root->right) {
            root->right->next = root->next ? root->next->left : NULL;
        }
        connect(root->left);
        connect(root->right);
    }
    */
    // version 2: nonrecursive
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        TreeLinkNode *start = root, *cur = start;
        while (start) {
            cur = start;
            while (cur) {
                if (cur->left) {
                    cur->left->next = cur->right;
                }
                if (cur->right) {
                    cur->right->next = cur->next ? cur->next->left : NULL;
                }
                cur = cur->next;
            }
            start = start->left;
        }
    }
};