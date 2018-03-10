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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return !root->left || !root->right ? max(minDepth(root->left), minDepth(root->right)) + 1 : min(minDepth(root->left), minDepth(root->right)) + 1;
    } 
    */
    // version 2 : non-recursive dfs 
    
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = INT_MAX;
        stack<TreeNode*> s;
        stack<int> sd;
        s.push(root);
        sd.push(1);
        while (!s.empty()) {
            TreeNode* node = s.top();
            int depth = sd.top();
            s.pop();
            sd.pop();
            if (!node->left && !node->right) {
                res = min(res, depth);
            }
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
    
    /*
    
    // version 3 : non-recursive bfs for loop
    int minDepth(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            res++;
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                TreeNode* node = q.front();
                q.pop();
                if ((!node->left && !node->right)){                    
                    return res;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return res; // return -1;
    }
    */
};