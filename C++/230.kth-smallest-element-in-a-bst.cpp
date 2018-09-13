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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        int count = 0;
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                count++;
                if (count == k) {
                    return s.top()->val;
                }
                node = s.top()->right;
                s.pop();
            }
        }
        return -1;
        
    }
};