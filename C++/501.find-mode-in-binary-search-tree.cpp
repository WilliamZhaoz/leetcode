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

// 10/3/2018 version:

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        long long cur = LONG_LONG_MIN, pre = cur;
        int c = 1, mc = 1;
        helper(root, cur, pre, res, c, mc);
        return res;
    }
    void helper(TreeNode *root, long long &cur, long long &pre, vector<int> &res, int &c, int &mc) {
        if (!root) {
            return;
        }
        helper(root->left, cur, pre, res, c, mc);
        cur = root->val;
        if (cur == pre) {
            c++;
            
        } else {
            c = 1;
        }
        if (c > mc) {
            res.clear();
            res.push_back(cur);
            mc = c;
        } else if (c == mc) {
            res.push_back(cur);
        }
        pre = cur;
        
        helper(root->right, cur, pre, res, c, mc);
    }
};