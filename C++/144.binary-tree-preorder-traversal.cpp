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

    // reference : http://blog.csdn.net/yimingsilence/article/details/54783208


    // recursive version
    
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return res;
        }
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
    
    /*
    // non-recursive version
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()) {
            if (node) {
                res.push_back(node->val);
                s.push(node);
                node = node->left;
            } else {
                node = s.top()->right;
                s.pop();
            }
        }
        return res;
    }
    */
};