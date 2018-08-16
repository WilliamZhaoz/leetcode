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
    // version 1: recursive, inorder traversal
    /*
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorderTraversal(root, target, k, res);
        return res;
    }
    void inorderTraversal(TreeNode* root, double target, int k, vector<int> &res) {
        if (!root) {
            return;
        }
        inorderTraversal(root->left, target, k, res);
        if (res.size() < k) {
            res.push_back(root->val);
        } else if (abs(res.front() - target) > abs(root->val - target)) {
            res.erase(res.begin());
            res.push_back(root->val);
        } else {
            return;
        }
        inorderTraversal(root->right, target, k, res);
    }
    */
    // version 1: recursive, inorder traversal
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *node = root;
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                if (res.size() < k) {
                    res.push_back(s.top()->val);
                } else if (abs(target - res[0]) > abs(target - s.top()->val)) {
                    res.erase(res.begin());
                    res.push_back(s.top()->val);
                } else {
                    return res;
                }
                node = s.top()->right;
                s.pop();
            }
        }
        return res;
    }


};