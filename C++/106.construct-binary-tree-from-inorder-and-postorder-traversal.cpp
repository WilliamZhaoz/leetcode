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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return helper(inorder, postorder, m, 0, n - 1, 0, n - 1);
    }
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &m, int inleft, int inright, int postleft, int postright) {
        if (inleft > inright) {
            return NULL;
        }
        int k = m[postorder[postright]];
        TreeNode* root = new TreeNode(postorder[postright]);
        root->left = helper(inorder, postorder, m, inleft, k - 1, postleft, postleft + (k - inleft - 1));
        root->right = helper(inorder, postorder, m, k + 1, inright, postleft + (k - inleft), postright - 1);
        return root;    
    }
};