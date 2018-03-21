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
    double pre = 0.5;
    int maxCount = INT_MIN;
    int curCount = 0;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(!root) {
            return res;
        }
        if (root->left) {
            findMode(root->left);
        }
        if (pre == root->val) {
            curCount++;
        } else {
            curCount = 0;
        }
        if (curCount >= maxCount) {
            if (curCount > maxCount) {
                res.clear();
                maxCount = curCount;
            }
            if (res.empty() || root->val != res.front()) {
                res.push_back(root->val);    
            }
        }
        pre = root->val;
        if (root->right) {
            findMode(root->right);
        }
        return res;
    }
};