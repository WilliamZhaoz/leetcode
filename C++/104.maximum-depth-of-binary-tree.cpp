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
    // version 1 : dfs recursive version
    
    /*
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        // return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
    */
    
    // version 2 : dfs non-recursive version
    /*
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }
        stack<TreeNode*> s;
        stack<int> sd;
        TreeNode* node = root;
        int depth = 1;
        while (!s.empty() || node) {
            if (node){
                s.push(node);
                sd.push(depth + 1);
                node = node->left;
                depth = sd.top();
            } else {
                node = s.top()->right;
                depth = sd.top();
                s.pop();
                sd.pop();
            }
            res = max(res, depth);
        }
        return res - 1;
    }
    */
    
    // version 3 : dfs non-recursive version 2
    /*
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }
        stack<TreeNode*> s;
        stack<int> sd;
        s.push(root);
        sd.push(1);
        while (!s.empty()) {
            TreeNode* node = s.top();
            int depth = sd.top();
            s.pop();
            sd.pop();
            res = max(res, depth);
            if (node->left) {
                s.push(node->left);
                sd.push(depth + 1);
            }
            if (node->right) {
                s.push(node->right);
                sd.push(depth + 1);
            }
        }
        return res;
    }
    */
    
    
    // version 3 : bfs non-recursive version 1 marker NULL
    /*
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                res++;
                if (!q.empty()) {
                    q.push(NULL);    
                }
            } else {
                if (node->left) {
                    q.push(node->left);    
                }
                if (node->right) {
                    q.push(node->right);    
                }
            }
        }
        return res;
    }
    */
    
    // version 4 : bfs non-recursive version 2 for loop
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res++;
        }
        return res;
    }
    
};