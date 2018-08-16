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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        if (root->val == target) {
            return res;
        } else if (root->val > target && root->left) {
            int left = closestValue(root->left, target);
            return abs(res - target) > abs(left - target) ? left : res; 
        } else if (root->right) {
            int right = closestValue(root->right, target);
            return abs(res - target) > abs(right - target) ? right : res;
        }
        return res;
    }
};