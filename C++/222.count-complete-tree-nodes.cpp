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
    int countNodes(TreeNode* root) {
        int dl = 0, dr = 0;
        TreeNode* nl = root, *nr = root;
        while (nl) {
            dl++;
            nl = nl->left;
        }
        while (nr) {
            dr++;
            nr = nr->right;
        }
        if (dl == dr) {
            return pow(2, dl) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    
    }
};