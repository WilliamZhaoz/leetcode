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
    // version 1 : recursive dfs
    /*
    long long pre = LONG_LONG_MIN;
    bool res = true;
    void dfs(TreeNode* root) {
        if (root->left) {
            isValidBST(root->left);    
        }
        if (root->val <= pre) {
            res = false;
        }
        pre = root->val;
        if (root->right) {
            isValidBST(root->right);    
        }
    }
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        dfs(root);
        return res;
    }
    */
     // version 2 : recursive dfs
    /*
    long lastVal = LONG_MIN;
    bool isValidBST(TreeNode * root) {
        if (!root) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (lastVal >= root->val) {
            return false;
        }
        lastVal = root->val;
        if (!isValidBST(root->right)) {
            return false;
        }
        return true;
    }
    */
    
    // version 3 : recursive dfs
    /*
    long lastVal = LONG_MIN;
    bool isValidBST(TreeNode * root) {
        if (!root) {
            return true;
        }
        bool left = isValidBST(root->left);
        if (root->val <= lastVal) {
            return false;
        }
        lastVal = root->val;
        bool right = isValidBST(root->right);
        return left && right;
    }
    */
    
    // version 4 : non-recursive dfs
    /*
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        stack<TreeNode*> s;
        TreeNode* node = root;
        long long pre = LONG_LONG_MIN;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                if (s.top()->val <= pre) {
                    return false;
                }
                pre = s.top()->val;
                node = s.top()->right;
                s.pop();
            }
        }
        return true;
    }
    */
    // version 5 : recursive divide & conquer
   /*
    bool isValidBST(TreeNode * root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
    */
    
   
};