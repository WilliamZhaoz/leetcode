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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> my_set;
        stack<TreeNode*> my_stack;
        my_stack.push(root);
        while(!my_stack.empty()) {
            TreeNode *node = my_stack.top();
            my_stack.pop();
            if (my_set.count(k - node->val)) {
                return true;
            }
            my_set.insert(node->val);
            if (node->right) {
                my_stack.push(node->right);
            }
            if (node->left) {
                my_stack.push(node->left);
            }
        }
        return false;
    }
};