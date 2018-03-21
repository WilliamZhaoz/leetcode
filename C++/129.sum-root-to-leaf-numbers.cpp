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
    // version 1 : self-recursive but change the tree values
    /*
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return root->val;
        }
        return (root->left ? root->left->val += root->val * 10, sumNumbers(root->left) : 0) + (root->right ? root->right->val += root->val * 10, sumNumbers(root->right) : 0); 
    }
    */
    // version 2 : recursive with helper
    
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    int helper(TreeNode* root, int cur) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return cur * 10 + root->val;
        }
        return helper(root->left, cur * 10 + root->val) + helper(root->right, cur * 10 + root->val);        
    }
    
    // version 3 : non-recursive - dfs need 2 stacks : one for TreeNode* one for current value 
    // version 4 : non-recursive - bfs need 2 queues : one for TreeNode* one for current value
    // version 5 & 6 : non-recursive - dfs or bfs need only 1 stack or queues but need to change node values like version 1
    // version 7 : non-recursive - post order traversal pfl:https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/41452/Iterative-C++-solution-using-stack-(similar-to-postorder-traversal)
    
};