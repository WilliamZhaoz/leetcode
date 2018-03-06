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
    
    // recursive version
    /*
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return res;
        }
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
    */
    
    // non-recursive version
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                res.push_back(s.top()->val);
                node = s.top()->right;
                s.pop();
            }
        }
        return res;
    }
};